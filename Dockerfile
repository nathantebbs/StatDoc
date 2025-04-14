FROM debian:bullseye-slim
LABEL Description="StatDoc Build Environment"

WORKDIR /code
COPY ./src ./src
COPY ./utils ./utils
COPY ./docs ./docs
COPY ./lib ./lib

RUN apt-get update && apt-get -y --no-install-recommends install \
	git \
	vim \
	make \
	cmake \
	build-essential \
	sudo \
	&& /code/utils/docker_test_integration.sh


