#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
uint8_t *buf;
size_t capacity;
size_t head;
size_t tail;
} ring_buffer_t;

int rb_init(ring_buffer_t *rb, uint8_t *mem, size_t capacity);
size_t rb_write(ring_buffer_t *rb, const uint8_t *data, size_t len);
size_t rb_read(ring_buffer_t *rb, uint8_t *out, size_t len);
size_t rb_available(const ring_buffer_t *rb);
size_t rb_free_space(const ring_buffer_t *rb);

#endif // RING_BUFFER_H
