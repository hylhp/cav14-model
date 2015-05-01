
 int audio_mutex = 0; //mutex var.

 int thd_create = 0;

thread_main() {
  thd_create = 1;
  audio_mutex = 1; //init var after create.
}

thread_child() {
  assume(thd_create == 1);
  assert (audio_mutex == 1);
}

void main() {
  thread_main();
  thread_child();
}
