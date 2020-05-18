/* queue and stack, not thread safe
*/
#ifndef __ELS_QUEUE_H_
#define __ELS_QUEUE_H_


#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>  // for memcpy()

#include "els.h"


typedef struct _ElsQueue {
	/** public */
	// input
	// output

	/** private */
	// parameter
	int16_t _queue_length;  // 队列长度
	size_t _item_size;  // 单个元素的长度，使用 sizeof 得到
	// variable
	uint_least8_t * _head;  // 指向缓存头
	uint_least8_t * _tail;  // 指向缓存尾，在分配的内存空间多于实际使用空间时使用
	uint_least8_t * _write_to;  // 指向下一个可以写入的地址
	uint_least8_t * _read_from;  // 指向待读出数据的前一个地址
	int16_t _items_in_queue;  // queue 中数据个数
} ElsQueue;

//---------------------------------------------------------------------------------------------------//

typedef struct {
	int16_t const queue_length;  // 队列中 item 的个数
	size_t const item_size;  // 队列每个元素的长度，使用 sizeof 得到
	const void * const queue_buf;  // 静态分配的缓存区首地址
} ElsQueueInitParam;

void els_queue_init(ElsQueue * self,
					const ElsQueueInitParam * param);

bool els_queue_push(ElsQueue * self, const void * data);

bool els_queue_push_to_front(ElsQueue * self, const void * data);

bool els_queue_pull(ElsQueue * self, void * data);

void els_queue_drop(ElsQueue * self);

// 作为 mailbox 使用，修改 mailbox 值，只修改 top 值
bool els_queue_overwrite(ElsQueue * self, const void * data);

// 作为 mailbox 使用，读取 mailbox 值，只读取 top 值
bool els_queue_peek(ElsQueue * self, void * data);

void els_queue_reset(ElsQueue * self);


static inline int16_t
els_queue_items_in_queue(const ElsQueue * const self)
{
	return self->_items_in_queue;
}


static inline bool
els_queue_is_full(const ElsQueue * const self)
{
	return (self->_items_in_queue >= self->_queue_length);
}


static inline bool
els_queue_is_empty(const ElsQueue * const self)
{
	return (self->_items_in_queue <= 0);
}


static inline int16_t
els_queue_left_room(const ElsQueue * const self)
{
	return (self->_queue_length - self->_items_in_queue);
}


#define els_queue_has_item(self)	!els_queue_is_empty(self)


#endif  // __ELS_QUEUE_H_


