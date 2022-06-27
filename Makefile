#
# Makefile
# dephilia, 2021-04-27 16:31
#

all: builds

init:
	@mkdir -p build; \
	cd build; \
	cmake .. -G "Ninja"

builds: init
	@cmake --build build

clean:
	@rm -rf build
	@echo "Clean build files."
