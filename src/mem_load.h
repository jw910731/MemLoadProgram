//
// Created by jw910731 on 2020/12/20.
//

#ifndef MEMLOADPROG_MEM_LOAD_H
#define MEMLOADPROG_MEM_LOAD_H

int setup_memfd();
void *dlopen_handle(int fd);
void error(const char *s);

#endif //MEMLOADPROG_MEM_LOAD_H
