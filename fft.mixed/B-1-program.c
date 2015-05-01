
int gID = 0;
int gTime = 0;
int crt_child = 0;

void main();
int thread_child2();
int thread_child1();
int thread_main();


void main() {
  gID = 0;
  thread_main();
  thread_child1();
  thread_child2();
}

int thread_child2() {
  assume(crt_child == 1);
  if (gID == 0) {
    gID = 1;
    gTime = 1;
  }
}

int thread_child1() {
  assume(crt_child == 1);
  if (gID == 0) {
    gID = 1;
    gTime = 1;
  }
}

int thread_main() {
  crt_child = 1;
  assert(gTime == 1);
}

