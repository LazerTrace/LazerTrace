ifndef PREFIX
PREFIX := /opt/local
endif

ifndef PNGPP
PNGPP := vendor/png++
endif

make_cflags := -Wall $(CFLAGS) -I$(PREFIX)/include -I$(PNGPP)
make_ldflags := $(LDFLAGS) -L$(PREFIX)/lib

ifndef NDEBUG
make_cflags := $(make_cflags) -g
make_ldflags := $(make_ldflags) -g
endif

ifndef LIBPNG_CONFIG
LIBPNG_CONFIG := libpng-config
endif


# Include your subdirectory Makefiles here!
include src/Makefile
# XXX Although png++ doesn't require building, other vendors might. Get
# on that.


deps := $(sources:.cpp=.dep)
objects := $(sources:.cpp=.o)
targets := $(sources:.cpp=$(bin_suffix))

all: $(deps) $(targets)

clean: clean-deps
	rm -f $(targets) $(objects)

.SUFFIXES:

.PHONY: all clean clean-deps

%$(bin_suffix): %.o
	g++ -o $@ $< $(make_ldflags) `$(LIBPNG_CONFIG) --ldflags`

%.o: %.cpp
	g++ -c -o $@ $< $(make_cflags) `$(LIBPNG_CONFIG) --cflags`


%.dep: %.cpp
	g++ -M $(CPPFLAGS) $(make_cflags) $< -o- | \
	  sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@

clean-deps:
	rm -f $(deps)

include $(deps)
