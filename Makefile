PROJECT := automotive-ecu-sim
BUILD_DIR := build
CFLAGS := -std=c11 -Wall -Wextra -Werror -O0 -g
INCLUDES := -Isrc -Isrc/core -Isrc/util -Isrc/diag -Isrc/drivers -Isrc/hal
SRC_HOST := \
	src/main.c \
	src/core/scheduler.c \
	src/core/ring_buffer.c \
	src/util/logger.c \
	src/diag/diag_cli.c \
	src/drivers/uart.c \
	src/hal/hal_host.c

host: $(BUILD_DIR)/host/ecu_app

$(BUILD_DIR)/host/ecu_app: $(SRC_HOST)
	@mkdir -p $(BUILD_DIR)/host
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: host clean
