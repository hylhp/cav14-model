
int band_width_var = 0;
int thd_create = 0;

void main();
int thread_main();
int malloc_var();
int use_var();
int thread_child();


void main() {
  thread_main();
  thread_child();
}

int thread_main() {
  malloc_var();
  thd_create = 1;
}

int malloc_var() {
  band_width_var = 1;
}

int use_var() {
  assert(band_width_var == 1);
}

int thread_child() {
  assume(thd_create == 1);
  use_var();
}

