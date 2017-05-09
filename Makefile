all: bubblesort insertionsort quicksort sorted

builddir:
	mkdir -p build/

bubblesort: builddir
	./.build.sh bubblesort.h src/bs.h

insertionsort: builddir
	./.build.sh insertionsort.h src/is.h

quicksort: builddir
	./.build.sh quicksort.h src/qs.h

sorted:
	./.build.sh sorted.h



clean:
	rm -rf build/*
