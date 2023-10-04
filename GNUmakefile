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
	@ ( \
		bash -c "echo $(shell pi-gcc)" \
)
	@ ( \
		bash -c "echo $(shell pi-clang)" \
)

