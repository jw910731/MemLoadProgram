//
// Created by jw910731 on 2020/12/20.
//

#include "mem_load.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <linux/memfd.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>

// add in link time
extern unsigned char _binary_src_main_libmain_so_start;
extern unsigned char _binary_src_main_libmain_so_end;
extern uint32_t _binary_src_main_libmain_so_size;

void error(const char *s){
    char result[strlen(s)+strlen("[-] ")];
    strcpy(result, "[-] ");
    strcat(result, s);
    perror(result);
    exit(EXIT_FAILURE);
}

int setup_memfd(){
    int memfd;
    memfd = memfd_create("main_prog_fd", 0);
    if (memfd == -1){
        error("memfd_create()");
    }
    if(write(memfd, &(_binary_src_main_libmain_so_start), &(_binary_src_main_libmain_so_end) - &(_binary_src_main_libmain_so_start)) < 0){
        close(memfd);
        error("write()");
    }
    return memfd;
}

void *dlopen_handle(int fd){
    char path[1024];
    snprintf(path, 1024, "/proc/%d/fd/%d", getpid(), fd);
    void *dlHandle = dlopen(path, RTLD_LAZY);
    if(!dlHandle){
        fprintf(stderr, "[-] dlopen(): %s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    return dlHandle;
}