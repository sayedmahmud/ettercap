
#ifndef EC_THREADS_H
#define EC_THREADS_H

#include <ec_stdint.h>
#include <pthread.h>

struct ec_thread {
   char *name;
   char *description;
   pthread_t id;
};

enum {
   EC_SELF = 0,
};

#define EC_THREAD_FUNC(x) void * x(void *args)
#define EC_THREAD_PARAM  args

extern char * ec_thread_getname(pthread_t id);
extern char * ec_thread_getdesc(pthread_t id);
extern void ec_thread_register(pthread_t id, char *name, char *desc);
extern pthread_t ec_thread_new(char *name, char *desc, void *(*function)(void *), void *args);
extern void ec_thread_destroy(pthread_t id);
extern void ec_thread_init(void);
extern void ec_thread_testcancel(void);
extern void ec_thread_kill_all(void);

#define RETURN_IF_NOT_MAIN() do{ if (strcmp(ec_thread_getname(EC_SELF), GBL_PROGRAM)) return; }while(0)

#endif

/* EOF */

// vim:ts=3:expandtab

