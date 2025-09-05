#include "ring_buffer.h"

int rb_init(ring_buffer_t *rb, uint8_t *mem, size_t capacity) 
{
    if (!rb || !mem || capacity == 0) return -1;

    rb->buf = mem;
    rb->capacity = capacity;
    rb->head = rb->tail = 0;

    return 0;
}

static size_t advance(size_t idx, size_t step, size_t cap) 
{ 
    return (idx + step) % cap; 
}

size_t rb_available(const ring_buffer_t *rb) 
{
    if (!rb) return 0;

    if (rb->head >= rb->tail) return rb->head - rb->tail;

    return rb->capacity - (rb->tail - rb->head);
}

size_t rb_free_space(const ring_buffer_t *rb) 
{ 
    return rb->capacity - rb_available(rb) - 1; 
}

size_t rb_write(ring_buffer_t *rb, const uint8_t *data, size_t len) 
{
    size_t wrote = 0;

    while (wrote < len && rb_free_space(rb) > 0) 
    {
        rb->buf[rb->head] = data[wrote++];
        rb->head = advance(rb->head, 1, rb->capacity);
    }

    return wrote;
}

size_t rb_read(ring_buffer_t *rb, uint8_t *out, size_t len) 
{
    size_t read = 0;

    while (read < len && rb_available(rb) > 0) 
    {
        out[read++] = rb->buf[rb->tail];
        rb->tail = advance(rb->tail, 1, rb->capacity);
    }

    return read;
}
