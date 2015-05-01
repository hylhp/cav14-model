                                         unsigned int nondet_int();
                                         int __assume_dummy = 0;



                                         int audio_mutex = 0;
                                         int thd_create = 0;

                                         void main();
                                         int thread_main();
                                         int thread_child();




                                         void main() {
                                           __CPROVER_ASYNC_1: thread_main();
                                           __CPROVER_ASYNC_1: thread_child();
                                            }

                                         int thread_main() {
__CPROVER_atomic_begin();                  audio_mutex = 1;                                                       __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  thd_create = 1;                                                        __CPROVER_atomic_end();
                                         }

                                         int thread_child() {
__CPROVER_atomic_begin();                  __CPROVER_assume(thd_create == 1); __assume_dummy=0;                   __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  assert(audio_mutex == 1);                                              __CPROVER_atomic_end();
                                         }


// Line: 32