                                         unsigned int nondet_int();
                                         int __assume_dummy = 0;



                                         int crt_read_thd = 0;
                                         int crt_close_thd = 0;
                                         int chd1_finish = 0;
                                         int chd2_finish = 0;
                                         int pointer_NULL = 1;

                                         void main();
                                         int thread_read1();
                                         int thread_read2();
                                         int thread_main();
                                         int thread_close();


                                         int __dummy = 0; //dummy to ensure the line shows up in the trace
                                         int __thread_read1_finished = 0;
                                         int __thread_read2_finished = 0;
                                         int __thread_main_finished = 0;
                                         int __thread_close_finished = 0;
                                         int __assert_fail = 0;


                                         void main() {
                                           __dummy=0; // function begin
                                           __dummy=0; __CPROVER_ASYNC_1: thread_main();
                                           __dummy=0; __CPROVER_ASYNC_1: thread_read1();
                                           __dummy=0; __CPROVER_ASYNC_1: thread_read2();
                                           __dummy=0; __CPROVER_ASYNC_1: thread_close();
                                           __dummy=0; // function end
                                           __CPROVER_assume(__thread_read1_finished == 1); __assume_dummy=0;
                                           __CPROVER_assume(__thread_read2_finished == 1); __assume_dummy=0;
                                           __CPROVER_assume(__thread_main_finished == 1); __assume_dummy=0;
                                           __CPROVER_assume(__thread_close_finished == 1); __assume_dummy=0;
                                           assert(__assert_fail == 0);
                                         }

                                         int thread_read1() {
                                           __dummy=0; // function begin
__CPROVER_atomic_begin();                  __CPROVER_assume(crt_read_thd == 1); __assume_dummy=0;                 __CPROVER_atomic_end();
__CPROVER_atomic_begin();
                                           if (pointer_NULL == 0)
                                             __dummy=0; //assertion passed
                                           else
                                             __assert_fail=1;
                                                                                                                  __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  chd1_finish = 1;                                                       __CPROVER_atomic_end();
                                           __dummy=0; // function end
                                           __thread_read1_finished = 1;
                                         }

                                         int thread_read2() {
                                           __dummy=0; // function begin
__CPROVER_atomic_begin();                  __CPROVER_assume(crt_read_thd == 1); __assume_dummy=0;                 __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  __CPROVER_assume(chd1_finish == 1); __assume_dummy=0;                  __CPROVER_atomic_end();
__CPROVER_atomic_begin();
                                           if (pointer_NULL == 0)
                                             __dummy=0; //assertion passed
                                           else
                                             __assert_fail=1;
                                                                                                                  __CPROVER_atomic_end();
                                           __dummy=0; // function end
                                           __thread_read2_finished = 1;
                                         }

                                         int thread_main() {
                                           __dummy=0; // function begin
__CPROVER_atomic_begin();                  pointer_NULL = 0;                                                      __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  crt_read_thd = 1;                                                      __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  crt_close_thd = 1;                                                     __CPROVER_atomic_end();
                                           __dummy=0; // function end
                                           __thread_main_finished = 1;
                                         }

                                         int thread_close() {
                                           __dummy=0; // function begin
__CPROVER_atomic_begin();                  __CPROVER_assume(crt_close_thd == 1); __assume_dummy=0;                __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  __CPROVER_assume(chd1_finish == 1); __assume_dummy=0;                  __CPROVER_atomic_end();
__CPROVER_atomic_begin();                  pointer_NULL = 1;                                                      __CPROVER_atomic_end();
                                           __dummy=0; // function end
                                           __thread_close_finished = 1;
                                         }


// Line: 88