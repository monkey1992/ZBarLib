#include <stdlib.h>

#include <android/log.h>
#include <string.h>
#include "iconv.h"

iconv_tt iconv_open(const char *tocode, const char *fromcode) {
    return NULL;
}

size_t iconv(iconv_tt cd, const char **inbuf, size_t *inbytesleft,
             char **outbuf, size_t *outbytesleft) {
    size_t sz = *inbytesleft;
    memcpy(*outbuf, *inbuf, sz);

    __android_log_print(ANDROID_LOG_DEBUG, "zbar", "convert: %s, sz=%d", *inbuf, sz);

    *inbuf += sz;
    *outbuf += sz;
    *inbytesleft -= sz;
    *outbytesleft -= sz;
    return sz;
}

int iconv_close(iconv_tt cd) {
    return 0;
}

