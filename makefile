all:

Life.log:
	git log > Life.log

Doxyfile:
	doxygen -g

html: Doxyfile Life.h Life.c++ RunLife.c++ TestLife.c++
	doxygen Doxyfile

RunLife: Life.h Life.c++ RunLife.c++
	g++-4.7 -pedantic -std=c++11 -Wall Life.c++ RunLife.c++ -o RunLife

RunLife.out: RunLife RunLife.in
	RunLife < RunLife.in > RunLife.out

RunLife.tmp: RunLife RunLife.in
	RunLife < RunLife.in > RunLife.tmp
	diff RunLife.tmp RunLife.out

TestLife: Life.h Life.c++ TestLife.c++
	g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Life.c++ TestLife.c++ -o TestLife -lgtest -lgtest_main -lpthread

TestLife.out: TestLife
	valgrind TestLife        >  TestLife.out 2>&1
	gcov-4.7 -b Life.c++     >> TestLife.out
	gcov-4.7 -b TestLife.c++ >> TestLife.out

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunLife
	rm -f RunLife.out
	rm -f RunLife.tmp
	rm -f TestLife
	rm -f TestLife.out
