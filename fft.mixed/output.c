                                         unsigned int nondet_int();
                                         int __assume_dummy = 0;



                                         int gID = 0;
                                         int gTime = 0;
                                         int crt_child = 0;

                                         void main();
                                         int thread_child2();
                                         int thread_child1();
                                         int thread_main();


                                         int __dummy = 0; //dummy to ensure the line shows up in the trace
                                         int __thread_child2_finished = 0;
                                         int __thread_child1_finished = 0;
                                         int __thread_main_finished = 0;
                                         int __assert_fail = 0;


                                         void main() {
                                           __dummy=0; // function begin
__CPROVER_atomic_begin();                  gID = 0;                                                               __CPROVER_atomic_end();
                                           __dummy=0; __CPROVER_ASYNC_1: thread_main();
                                           __dummy=0; __CPROVER_ASYNC_1: thread_child1();
                                           __dummy=0; __CPROVER_ASYNC_1: thread_child2();
                                           __dummy=0; // function end
                                           __CPROVER_assume(__thread_child2_finished == 1); __assume_dummy=0;
                                           __CPROVER_assume(__thread_child1_finished == 1); __assume_dummy=0;
                                           __CPROVER_assume(__thread_main_finished == 1); __assume_dummy=0;
                                           assert(__assert_fail == 0);
                                         }

                                         int thread_child2() {
                                           __dummy=0; // function begin
__CPROVER_atomic_begin();                  __CPROVER_assume(crt_child == 1); __assume_dummy=0;                    __CPROVER_atomic_end();
                                           int __test39;
__CPROVER_atomic_begin();                  __test39 = gID == 0;                                                   __CPROVER_atomic_end();
                                           if (__test39) {
__CPROVER_atomic_begin();                    gID = 1;                                                             __CPROVER_atomic_end();
__CPROVER_atomic_begin();                    gTime = 1;                                                           __CPROVER_atomic_end();
                                           }
                                           __dummy=0; // function end
                                           __thread_child2_finished = 1;
                                         }

                                         int thread_child1() {
                                           __dummy=0; // function begin
__CPROVER_atomic_begin();                  __CPROVER_assume(crt_child == 1); __assume_dummy=0;                    __CPROVER_atomic_end();
                                           int __test52;
__CPROVER_atomic_begin();                  __test52 = gID == 0;                                                   __CPROVER_atomic_end();
                                           if (__test52) {
__CPROVER_atomic_begin();                    gID = 1;                                                             __CPROVER_atomic_end();
__CPROVER_atomic_begin();                    gTime = 1;                                                           __CPROVER_atomic_end();
                                           }
                                           __dummy=0; // function end
                                           __thread_child1_finished = 1;
                                         }

                                         int thread_main() {
                                           __dummy=0; // function begin
__CPROVER_atomic_begin();                  crt_child = 1;                                                         __CPROVER_atomic_end();
__CPROVER_atomic_begin();
                                           if (gTime == 1)
                                             __dummy=0; //assertion passed
                                           else
                                             __assert_fail=1;
                                                                                                                  __CPROVER_atomic_end();
                                           __dummy=0; // function end
                                           __thread_main_finished = 1;
                                         }


// Line: 76