
 int band_width_var = 0;

 int thd_create = 0;

thread_main() {
  thd_create = 1;//create a thd before var initializing.
  malloc_var();
}


thread_child() {
  assume(thd_create == 1);
  use_var();
}

malloc_var() {
  band_width_var = 1;
}

use_var() {
  assert(band_width_var == 1);
}

void main() {
  thread_main();
  thread_child();
}
