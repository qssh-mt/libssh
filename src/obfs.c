#include <stdlib.h>
#include <string.h>
#include <libssh/obfs.h>

void obfs_envelope_allocate(struct obfs_envelope_struct *envelope, uint32_t len) {
    envelope->payload = calloc(len, sizeof(uint8_t));
    if (envelope->payload == NULL) {
        exit(EXIT_FAILURE);
    }
}

void obfs_envelope_free(struct obfs_envelope_struct *envelope) {
    if(envelope->payload) {
        free(envelope->payload);
        envelope->payload = NULL;
    }
    memset(envelope->nonce, 0, 16 * sizeof(uint8_t));
    memset(envelope->tag, 0, 16 * sizeof(uint8_t));
}
