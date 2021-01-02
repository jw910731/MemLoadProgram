#include <stdio.h>
#include <dlfcn.h>
#include <stdint.h>
#include "mem_load.h"

extern uint8_t _binary_src_main_libmain_so_start;
extern uint8_t _binary_src_main_libmain_so_end;
extern uint32_t _binary_src_main_libmain_so_size;

int main() {
    
    fprintf(stderr, "[info] Section Size: %lu\n", &(_binary_src_main_libmain_so_end) - &(_binary_src_main_libmain_so_start));
    int fd = setup_memfd();
    void *handle = dlopen_handle(fd);
    if (handle == NULL){

    }
    int (*main_prog)();
    main_prog = (int(*)())dlsym(handle, "entry");
    if(main_prog != NULL){
        main_prog();
    }
    else{
        fprintf(stderr, "[-] dlsym error\n");
    }
    dlclose(handle);
    return 0;
}
