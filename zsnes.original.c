
int audio_mutex = 0;
int thd_create = 0;

void main();
int thread_main();
int thread_child();


void main() {
  thread_main();
  thread_child();
}

int thread_main() {
  thd_create = 1;
  if (thd_create == 1) {
    audio_mutex = 1;
  }
}

int thread_child() {
  assume(thd_create == 1);
  assert(audio_mutex == 1);
}

