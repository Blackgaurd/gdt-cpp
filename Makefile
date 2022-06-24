SRC_DIR := src
BIN_DIR := bin
INCLUDE_DIR := include
MODEL_DIR := models

SRC := $(wildcard $(SRC_DIR)/*.cpp)

CPPFLAGS := -I$(INCLUDE_DIR) -std=c++17 -Wall -Wextra -Wfatal-errors

.PHONY: all
all:
	mkdir -p $(BIN_DIR)
	g++ $(CPPFLAGS) $(SRC) $(MODEL_DIR)/$(MODEL).cpp -o $(BIN_DIR)/$(MODEL)
