CXX = clang++-17
LFLAGS = -std=c++14 -Wall

all: LFLAGS += -Ofast -march=native
all: enwik9-preproc

debug: LFLAGS += -ggdb
debug: enwik9-preproc

enwik9-preproc: article_reorder.h main.cpp misc.h
	$(CXX) $(LFLAGS) main.cpp -o enwik9-preproc

clean:
	rm -f enwik9-preproc
