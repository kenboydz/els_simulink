#ifndef __ELS_ASSERT_H__
#define __ELS_ASSERT_H__

#include <stdint.h>
#include <stdbool.h>


#ifdef ELS_ENABLE_ASSERT


#define ELS_DEFINE_THIS_MODULE(name) \
    static const char _els_this_module[] = name;

#define ELS_AVOID_UNUSED(var) do { (void)(var); } while (0)

#define ELS_ASSERT_STATIC(rst) \
    extern int32_t _els_assert_static[(rst) ? 1 : -1];

#define ELS_ASSERT(rst) \
    ((rst) ? (void)0 : els_on_assert(&_els_this_module[0], (const int32_t)__LINE__))

#define ELS_ASSERT_FILE(rst) \
    ((rst) ? (void)0 : els_on_assert((const char *)__FILE__, (const int32_t)__LINE__))

#define ELS_ERROR() ELS_ASSERT(false)

#define ELS_ERROR_ID(id_) els_on_assert((const char *)__FILE__, (const int32_t)id_)

#define ELS_NEED_OVERRIDE() ELS_ERROR()

extern void els_on_assert(const char * const name, const uint32_t line);


#else


#define ELS_DEFINE_THIS_MODULE(name)
#define ELS_AVOID_UNUSED(var)
#define ELS_ASSERT_STATIC(rst)
#define ELS_ASSERT(rst)
#define ELS_ASSERT_FILE(rst)
#define ELS_ERROR()
#define ELS_ERROR_ID(id_)
#define ELS_NEED_OVERRIDE()


#endif  // ELS_ENABLE_ASSERT


#endif  // __ELS_ASSERT_H__
