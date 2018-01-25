.PHONY: help

help: ## This help.
	@awk 'BEGIN {FS = ":.*?## "} /^[0-9a-zA-Z_-]+:.*?## / {printf "\033[36m%-40s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)

.DEFAULT_GOAL := help

# DOCKER TASKS
xenial-cpp-env-tdd-book: ## Build Custom Xenial Enviroment with exactly same book libraries | (non NVIDIA)
	./build.sh generic-card codookie/xenial:cpp-env-tdd-book
	@printf "\n\033[92mDocker Image: codookie/xenial:cpp-env-tdd-book\033[0m\n"
xenial-cpp-env-tdd-book-nvidia: xenial-cpp-env-tdd-book ## Build Custom Xenial Enviroment with exactly same book libraries | (for NVIDIA & OpenGL)
	./build.sh nvidia-opengl codookie/xenial:cpp-env-tdd-book-nvidia
	@printf "\n\033[92mDocker Image: codookie/xenial:cpp-env-tdd-book-nvidia\033[0m\n"