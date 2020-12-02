#ifndef OBFS_H
#define OBFS_H

#include <stdint.h>

struct obfs_envelope_struct {
    uint8_t nonce[16];
    uint8_t *payload;
    uint8_t tag[16];
};


void obfs_envelope_allocate(struct obfs_envelope_struct *envelope, uint32_t len);

void obfs_envelope_free(struct obfs_envelope_struct *envelope);

#endif
