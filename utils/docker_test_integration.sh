#! /bin/bash

if [[ -d "/code" ]]; then
	cd /code/googletest
	mkdir build
	cd build
	cmake ..
	cd googletest && make
	sudo make install

	echo "Test Integration Success"
	exit 0
fi

echo "ERROR: Please execute inside the provided docker container"
exit 1
