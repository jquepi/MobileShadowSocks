#ifndef _ENCRYPT_H
#define _ENCRYPT_H

#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "md5.h"
#include "rc4.h"

#define BUF_SIZE 4096

#define TABLE 0
#define RC4   1

union {
    struct {
        unsigned char *encrypt_table;
        unsigned char *decrypt_table;
    } table;

    struct {
        unsigned char *key;
        int key_len;
    } rc4;
} enc_ctx;

void get_table(const char* key);
void encrypt_ctx(char *buf, int len, struct rc4_state *ctx);
void decrypt_ctx(char *buf, int len, struct rc4_state *ctx);
void enc_ctx_init(struct rc4_state *ctx, int enc);
void enc_key_init(const char *pass);

unsigned int _i;
unsigned long long _a;
int _method;


#ifdef DEBUG
#define perror(str) (LOGE("%s\n", str))
#define LOGD(...) ((void)fprintf(stderr, __VA_ARGS__))
#define LOGE(...) ((void)fprintf(stderr, __VA_ARGS__))
#else
#define perror(str)
#define LOGD(...)
#define LOGE(...)
#endif

#endif // _ENCRYPT_H