
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


void main() {
  thread_main();
  thread_read1();
  thread_read2();
  thread_close();
}

int thread_read1() {
  assume(crt_read_thd == 1);
  assert(pointer_NULL == 0);
  chd1_finish = 1;
}

int thread_read2() {
  assume(crt_read_thd == 1);
  assume(chd1_finish == 1);
  assert(pointer_NULL == 0);
}

int thread_main() {
  pointer_NULL = 0;
  crt_read_thd = 1;
  crt_close_thd = 1;
}

int thread_close() {
  assume(crt_close_thd == 1);
  assume(chd1_finish == 1);
  pointer_NULL = 1;
}

