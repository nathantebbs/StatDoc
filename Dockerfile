FROM debian:bullseye-slim
LABEL Description="StatDoc Build Environment"

WORKDIR /code
COPY ./src ./src
COPY ./Makefile ./Makefile
COPY ./lib/googletest ./googletest
COPY ./utils/docker_test_integration.sh ./docker_test_integration.sh

RUN apt-get update && apt-get -y --no-install-recommends install \
	git \
	vim \
	make \
	cmake \
	build-essential \
	sudo \
	&& /code/docker_test_integration.sh


