#include <stdio.h>
#include <dlfcn.h>
#include "mem_load.h"

int main() {
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
