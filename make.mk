-:gcc clang gnostr-pi

.PHONY:gcc clang gnostr gnostr-pi gnostr
gnostr-pi:gnostr
gnostr:
	@gcc src/pi.c -o $@-pi || $(shell which $@-pi)
	@install ./$@-pi /usr/local/bin/ || $(shell which $@-pi)
gcc:
	@$@ src/pi.c -o pi-$@ || $(shell which $@)
	@install ./pi-$@ /usr/local/bin/ || $(shell which $@)
clang:
	@$@ src/pi.c -o pi-$@ || $(shell which $@)
	@install ./pi-$@ /usr/local/bin/ || $(shell which $@)
test:gcc-test clang-test gnostr-test
.PHONY:gnostr-test
gnostr-test:-
	@install ./gnostr-pi /usr/local/bin/
	./gnostr-pi
	./gnostr-pi 360   > ./logs/360.txt   
	./gnostr-pi 1000  > ./logs/1000.txt  
	./gnostr-pi 360 1 > ./logs/360_1.txt 
	./gnostr-pi 100 2 > ./logs/100_2.txt 
	./gnostr-pi 1000 -253 > ./logs/1000_-253.txt
	git diff logs >> diff.log
gcc-test:-
	@install ./pi-gcc /usr/local/bin/
	./pi-gcc && \
	./pi-gcc 360   > ./logs/360.txt   
	./pi-gcc 1000  > ./logs/1000.txt  
	./pi-gcc 360 1 > ./logs/360_1.txt 
	./pi-gcc 100 2 > ./logs/100_2.txt 
	git diff logs >> diff.log
clang-test:-
	@install ./pi-clang /usr/local/bin/
	pi-clang && \
	pi-clang 360   > ./logs/360.txt   
	pi-clang 1000  > ./logs/1000.txt  
	pi-clang 360 1 > ./logs/360_1.txt 
	pi-clang 100 2 > ./logs/100_2.txt 
	git diff logs >> diff.log
gcc-test2:
	@( \
	bash -c "pi-gcc   11111 | sed 's/\./_/'" \
)
clang-test2:
	@( \
	bash -c "pi-clang 11111 | sed 's/\./_/'" \
)

gcc-test3:
	@( \
	bash -c "pi-gcc   11111 | sed 's/3\.//'" \
)

clang-test3:
	@( \
	bash -c "pi-clang 11111 | sed 's/3\.//'" \
)

clean:
	@rm gnostr-* 2>/dev/null || true
	@rm pi-*     2>/dev/null || true
	@rm a.out    2>/dev/null || true
