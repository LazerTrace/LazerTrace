#include <tut/tut.hpp>
#include <tut_reporter.h>
#include <iostream>

using std::exception;
using std::cerr;
using std::endl;

namespace tut {
    test_runner_singleton runner;
}

int main() {
    tut::reporter reporter;
    tut::runner.get().set_callback(&reporter);

    tut::runner.get().run_tests();

    return !reporter.all_ok();
}
