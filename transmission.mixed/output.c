                                         unsigned int nondet_int();
                                         int __assume_dummy = 0;



                                         int band_width_var = 0;
                                         int thd_create = 0;

                                         void main();
                                         int thread_main();
                                         int malloc_var();
                                         int use_var();
                                         int thread_child();




                                         void main() {
                                           __CPROVER_ASYNC_1: thread_main();
                                           __CPROVER_ASYNC_1: thread_child();
                                            }

                                         int thread_main() {
                                           malloc_var();
__CPROVER_atomic_begin();                  thd_create = 1;                                                        __CPROVER_atomic_end();
                                         }

                                         int malloc_var() {
__CPROVER_atomic_begin();                  band_width_var = 1;                                                    __CPROVER_atomic_end();
                                         }

                                         int use_var() {
__CPROVER_atomic_begin();                  assert(band_width_var == 1);                                           __CPROVER_atomic_end();
                                         }

                                         int thread_child() {
__CPROVER_atomic_begin();                  __CPROVER_assume(thd_create == 1); __assume_dummy=0;                   __CPROVER_atomic_end();
                                           use_var();
                                         }


// Line: 42