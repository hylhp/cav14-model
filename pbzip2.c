
 int crt_output_thd = 0; //create output thd
 int crt_decompress_thd = 0; //create decompress thd
 
 int fifo_empty = 0; //fifo empty flag

 int decompress_thd_finish = 0; //decompress thd finish flag
 int output_finish = 0; //output thd finish flag

thread_main() {
  crt_decompress_thd = 1;
  crt_output_thd = 1; //create decompress and output thds.
  assume(output_finish == 1); //wait output thd.
  fifo_empty = 1; //free fifo. forget to wait decompress thd.
}

thread_decompress1() {
  assume(crt_decompress_thd == 1);
  assert (fifo_empty == 0);
  decompress_thd_finish = 1;
}

thread_decompress2() {
  assume(crt_decompress_thd == 1);
  assert (fifo_empty == 0);
  decompress_thd_finish = 2;
}

thread_output() {
  assume(crt_decompress_thd == 1);
  assume(crt_output_thd == 1);
  assume(decompress_thd_finish == 1);
  output_finish = 1;
}

void main() {
  fifo_empty = 0;
  output_finish = 0;
  thread_main();
  thread_decompress1();
  thread_decompress2();
  thread_output();
}
