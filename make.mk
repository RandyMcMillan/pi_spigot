-:gcc clang gnostr-pi
##default gcc
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
test-all:gnostr gcc clang
	@echo "gnostr-test" && $(MAKE) gnostr-test
	@echo "gcc-test"    && $(MAKE)    gcc-test
	@echo "clang-test"  && $(MAKE) clang-test
test:gcc-test clang-test gnostr-test
gnostr-test:-
	@install ./gnostr-pi /usr/local/bin/
	@( \
		bash -c "gnostr-pi" \
		bash -c "gnostr-pi 360 > logs/360" \
)
gcc-test:-
	@install ./pi-gcc /usr/local/bin/
	@( \
		bash -c "pi-gcc" \
		bash -c "pi-gcc 360 > logs/360" \
)
clang-test:-
	@install ./pi-clang /usr/local/bin/
	@( \
		bash -c "pi-clang" \
		bash -c "pi-clang 360 > logs/360" \
)
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
