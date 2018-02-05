CFLAGS = -Wall -fpic -coverage -lm

build_testme: testme.c
	gcc -o testme testme.c $(CFLAGS)

run_testme: testme
	./testme

clean:
	rm -f testme