-:gcc clang
##default gcc
.PHONY:gcc clang
gnostr:
	@gcc src/pi.c -o $@-pi || $(shell which $@)
	@install ./$@-pi /usr/local/bin/ || $(shell which $@-pi)
	@##@file $@-pi
gcc:
	@$@ src/pi.c -o pi-$@ || $(shell which $@)
	@install ./pi-$@ /usr/local/bin/ || $(shell which pi-$@)
	@##@file pi-$@
clang:
	@$@ src/pi.c -o pi-$@ || $(shell which $@)
	@install ./pi-$@ /usr/local/bin/ || $(shell which pi-$@)
	@##@file pi-$@
test-all:
	@echo "gcc-test"   && $(MAKE)   gcc-test
	@echo "clang-test" && $(MAKE) clang-test
test:gcc-test clang-test
gcc-test:-
	@install ./pi-gcc /usr/local/bin/
	@( \
		bash -c "echo $(shell pi-gcc)" \
		bash -c "echo $(shell pi-gcc 360) > logs/360" \
)
clang-test:-
	@install ./pi-clang /usr/local/bin/
	@( \
		bash -c "echo $(shell pi-clang)" \
		bash -c "echo $(shell pi-gcc 360) > logs/360" \
)
gcc-test2:
	@( \
	bash -c "echo $(shell pi-gcc   11111) | sed 's/\./_/'" \
)
clang-test2:
	echo $(shell pi-clang 11111) | sed 's/\./_/'
gcc-test3:
	echo $(shell pi-gcc   11111) | sed 's/3\.//'
clang-test3:
	echo $(shell pi-clang 11111) | sed 's/3\.//'
clean:
	@rm pi-gcc   2>/dev/null || true
	@rm pi-clang 2>/dev/null || true
	@rm a.out    2>/dev/null || true
