-:gcc clang
gcc:
	@$@ pi.c -o pi-$@ || $(shell which $@)
clang:
	@$@ pi.c -o pi-$@ || $(shell which $@)
test:
	@$(MAKE) gcc || echo
	@$(MAKE) clang || echo
	@install ./pi-gcc /usr/local/bin/
	@install ./pi-clang /usr/local/bin/
	(\
		PI_GCC=$(shell pi-gcc) \
	)
	$(shell echo $(PI_GCC))
	(\
		PI_CLANG=$(shell pi-clang) \
	)
	$(shell echo $(PI_CLANG))

