#ifndef CTRICKS_THREAD_H
#define CTRICKS_THREAD_H

#define start_thread(pthread, body) pthread_create(&pthread, NULL, lambda(void *, () body), NULL);

#endif
