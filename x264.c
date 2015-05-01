
 int crt_read_thd = 0; //create child thd flag
 int crt_close_thd = 0;

 int chd1_finish = 0; // child thd finish flag
 int chd2_finish = 0;

 int pointer_NULL = 1; //pointer null flag

thread_main() {
  pointer_NULL = 0;
  crt_read_thd = 1; //create read thd.
  crt_close_thd = 1; //create close thd.
}

thread_read1() {
  assume(crt_read_thd == 1); //wait main thd create.
  assert(pointer_NULL == 0); 
  chd1_finish = 1;
}

thread_read2() {
  assume(crt_read_thd == 1);
  assume(chd1_finish == 1); //wait read thd1 finish.
  assert(pointer_NULL == 0);
}

thread_close() {
  assume(crt_close_thd == 1);
  assume(chd1_finish == 1); //forget to wait the last read thd.
  pointer_NULL = 1;
}

void main() {
  thread_main();
  thread_read1();
  thread_read2();
  thread_close();
}
