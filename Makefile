ifndef PNGPP
PNGPP := vendor/png++
endif

ifndef OPENCTM
OPENCTM := vendor/OpenCTM/lib
endif

ifndef JSONCPP
JSONCPP := vendor/jsoncpp/include
endif

ifndef LIBPNG_CONFIG
LIBPNG_CONFIG = libpng-config
endif

make_cflags = -Wall -Wextra -pedantic -O $(CFLAGS) -I$(PNGPP) -I$(OPENCTM) -I$(JSONCPP) -Ivendor/tut `$(LIBPNG_CONFIG) --cflags`
make_ldflags = $(LDFLAGS)

ifndef NDEBUG
make_cflags := $(make_cflags) -g
make_ldflags := $(make_ldflags) -g
endif

CPATH=src

# Include your subdirectory Makefiles here!
include src/Makefile
include test/Makefile
# XXX Although png++ doesn't require building, other vendors might. Get
# on that.


deps := $(shared_sources:.cpp=.dep) $(main_sources:.cpp=.dep)
shared_objects := $(shared_sources:.cpp=.o)
main_objects := $(main_sources:.cpp=.o)
test_objects := $(test_sources:.cpp=.o)
objects := $(shared_objects) $(main_objects) $(test_objects)
targets := bin/main bin/test

$(shared_objects): make_cflags := $(make_cflags) -Weffc++

all: $(deps) $(targets) check

clean: clean-deps
	rm -f $(targets) $(objects)

.SUFFIXES:

.PHONY: all clean clean-deps targets deps check

check: bin/test
	bin/test

bin/main: $(shared_objects) $(main_objects)
	g++ -o $@ $^ $(make_ldflags) -lpthread `$(LIBPNG_CONFIG) --ldflags`

bin/test: $(shared_objects) $(test_objects)
	g++ -o $@ $^ $(make_ldflags) `$(LIBPNG_CONFIG) --ldflags`

%.o: %.cpp
	CPATH=$(CPATH) g++ -c -o $@ $< $(make_cflags)


%.dep: %.cpp
	@g++ -M $(CPPFLAGS) $(make_cflags) $< -o- | \
	  sed '1s#[^ ]*.o[ :]*#$*.o: #' > $@

clean-deps:
	rm -f $(deps)

-include $(deps)
