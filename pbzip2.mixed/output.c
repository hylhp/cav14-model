                                         unsigned int nondet_int();
                                         int __assume_dummy = 0;



                                         int crt_output_thd = 0;
                                         int crt_decompress_thd = 0;
                                         int fifo_empty = 0;
                                         int decompress_thd_finish = 0;
                                         int output_finish = 0;

                                         void main();
                                         int thread_output();
                                         int thread_decompress1();
                                         int thread_main();
                                         int thread_decompress2();




                                         void main() {
__CPROVER_atomic_begin();                  fifo_empty = 0;                                                        __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  output_finish = 0;                                                     __CPROVER_atomic_end();
                                           __CPROVER_ASYNC_1: thread_main();
                                           __CPROVER_ASYNC_1: thread_decompress1();
                                           __CPROVER_ASYNC_1: thread_decompress2();
                                           __CPROVER_ASYNC_1: thread_output();
                                            }

                                         int thread_output() {
__CPROVER_atomic_begin();                  __CPROVER_assume(crt_decompress_thd == 1); __assume_dummy=0;           __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  __CPROVER_assume(crt_output_thd == 1); __assume_dummy=0;               __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  __CPROVER_assume(decompress_thd_finish == 1); __assume_dummy=0;        __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  output_finish = 1;                                                     __CPROVER_atomic_end();
                                         }

                                         int thread_decompress1() {
__CPROVER_atomic_begin();                  __CPROVER_assume(crt_decompress_thd == 1); __assume_dummy=0;           __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  assert(fifo_empty == 0);                                               __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  decompress_thd_finish = 1;                                             __CPROVER_atomic_end();
                                         }

                                         int thread_main() {
__CPROVER_atomic_begin();                  crt_decompress_thd = 1;                                                __CPROVER_atomic_end();
                                           __CPROVER_atomic_begin();
                                             crt_output_thd = 1;                                                  
                                             __CPROVER_assume(output_finish == 1); __assume_dummy=0;              
                                           __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  fifo_empty = 1;                                                        __CPROVER_atomic_end();
                                         }

                                         int thread_decompress2() {
__CPROVER_atomic_begin();                  __CPROVER_assume(crt_decompress_thd == 1); __assume_dummy=0;           __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  assert(fifo_empty == 0);                                               __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  decompress_thd_finish = 2;                                             __CPROVER_atomic_end();
                                         }


// Line: 59