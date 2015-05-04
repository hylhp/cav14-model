
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
  fifo_empty = 0;
  output_finish = 0;
  thread_main();
  thread_decompress1();
  thread_decompress2();
  thread_output();
}

int thread_output() {
  assume(crt_decompress_thd == 1);
  assume(crt_output_thd == 1);
  assume(decompress_thd_finish == 1);
  output_finish = 1;
}

int thread_decompress1() {
  assume(crt_decompress_thd == 1);
  assert(fifo_empty == 0);
  decompress_thd_finish = 1;
}

int thread_main() {
  crt_decompress_thd = 1;
  crt_output_thd = 1;
  assume(output_finish == 1);
  fifo_empty = 1;
}

int thread_decompress2() {
  assume(crt_decompress_thd == 1);
  assert(fifo_empty == 0);
  decompress_thd_finish = 2;
}

