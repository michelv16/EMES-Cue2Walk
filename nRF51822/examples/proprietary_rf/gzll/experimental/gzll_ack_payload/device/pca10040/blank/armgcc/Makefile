PROJECT_NAME     := gzll_ack_payload_device_pca10040
TARGETS          := nrf52832_xxaa
OUTPUT_DIRECTORY := _build

SDK_ROOT := ../../../../../../../../..
PROJ_DIR := ../../..

$(OUTPUT_DIRECTORY)/nrf52832_xxaa.out: \
  LINKER_SCRIPT  := gzll_ack_payload_device_gcc_nrf52.ld
# Source files common to all targets
SRC_FILES += \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_serial.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_frontend.c \
  $(SDK_ROOT)/components/libraries/button/app_button.c \
  $(SDK_ROOT)/components/libraries/util/app_error.c \
  $(SDK_ROOT)/components/libraries/util/app_error_weak.c \
  $(SDK_ROOT)/components/libraries/timer/app_timer.c \
  $(SDK_ROOT)/components/libraries/util/app_util_platform.c \
  $(SDK_ROOT)/components/libraries/util/nrf_assert.c \
  $(SDK_ROOT)/components/drivers_nrf/common/nrf_drv_common.c \
  $(SDK_ROOT)/components/drivers_nrf/gpiote/nrf_drv_gpiote.c \
  $(SDK_ROOT)/components/drivers_nrf/uart/nrf_drv_uart.c \
  $(PROJ_DIR)/../../../../../bsp/bsp.c \
  $(PROJ_DIR)/main.c \
  $(SDK_ROOT)/external/segger_rtt/RTT_Syscalls_GCC.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_printf.c \
  $(SDK_ROOT)/components/toolchain/gcc/gcc_startup_nrf52.S \
  $(SDK_ROOT)/components/toolchain/system_nrf52.c \

# Include folders common to all targets
INC_FOLDERS += \
  $(PROJ_DIR)/config \
  $(SDK_ROOT)/components/toolchain/gcc \
  $(SDK_ROOT)/components/drivers_nrf/common \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
  $(SDK_ROOT)/components/drivers_nrf/uart \
  $(SDK_ROOT)/components \
  $(SDK_ROOT)/components/device \
  $(SDK_ROOT)/components/libraries/timer \
  $(PROJ_DIR) \
  $(SDK_ROOT)/components/toolchain \
  $(SDK_ROOT)/components/libraries/util \
  $(SDK_ROOT)/components/drivers_nrf/delay \
  ../config \
  $(SDK_ROOT)/components/drivers_nrf/hal \
  $(SDK_ROOT)/components/libraries/button \
  $(SDK_ROOT)/components/libraries/log/src \
  $(SDK_ROOT)/components/drivers_nrf/nrf_soc_nosd \
  $(SDK_ROOT)/components/proprietary_rf/gzll \
  $(PROJ_DIR)/../../../../../bsp \
  $(SDK_ROOT)/components/libraries/log \
  $(SDK_ROOT)/components/drivers_nrf/gpiote \
  $(SDK_ROOT)/external/segger_rtt \

# Libraries common to all targets
LIB_FILES += \
  $(SDK_ROOT)/components/proprietary_rf/gzll/gcc/gzll_nrf52_sd_resources_gcc.a \

# C flags common to all targets
CFLAGS += -DGAZELL_PRESENT
CFLAGS += -DNRF52
CFLAGS += -DBOARD_PCA10040
CFLAGS += -DNRF52832
CFLAGS += -DNRF52_PAN_12
CFLAGS += -DNRF52_PAN_15
CFLAGS += -DNRF52_PAN_58
CFLAGS += -DNRF52_PAN_55
CFLAGS += -DNRF52_PAN_54
CFLAGS += -DUSE_SD_HW_RESOURCES
CFLAGS += -DNRF52_PAN_30
CFLAGS += -DNRF52_PAN_51
CFLAGS += -DNRF52_PAN_36
CFLAGS += -DNRF52_PAN_53
CFLAGS += -DGAZELL_ALTERNATIVE_RESOURCES
CFLAGS += -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DSWI_DISABLE0
CFLAGS += -DNRF52_PAN_20
CFLAGS += -DNRF52_PAN_64
CFLAGS += -DNRF52_PAN_62
CFLAGS += -DNRF52_PAN_63
CFLAGS += -DNRF52_PAN_31
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs
CFLAGS +=  -Wall -Werror -O3 -g3
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in separate section, this allows linker to discard unused ones
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin --short-enums 
# generate dependency output file
CFLAGS += -MP -MD

# C++ flags common to all targets
CXXFLAGS += \

# Assembler flags common to all targets
ASMFLAGS += -x assembler-with-cpp
ASMFLAGS += -DGAZELL_PRESENT
ASMFLAGS += -DNRF52
ASMFLAGS += -DBOARD_PCA10040
ASMFLAGS += -DNRF52832
ASMFLAGS += -DNRF52_PAN_12
ASMFLAGS += -DNRF52_PAN_15
ASMFLAGS += -DNRF52_PAN_58
ASMFLAGS += -DNRF52_PAN_55
ASMFLAGS += -DNRF52_PAN_54
ASMFLAGS += -DUSE_SD_HW_RESOURCES
ASMFLAGS += -DNRF52_PAN_30
ASMFLAGS += -DNRF52_PAN_51
ASMFLAGS += -DNRF52_PAN_36
ASMFLAGS += -DNRF52_PAN_53
ASMFLAGS += -DGAZELL_ALTERNATIVE_RESOURCES
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DSWI_DISABLE0
ASMFLAGS += -DNRF52_PAN_20
ASMFLAGS += -DNRF52_PAN_64
ASMFLAGS += -DNRF52_PAN_62
ASMFLAGS += -DNRF52_PAN_63
ASMFLAGS += -DNRF52_PAN_31

# Linker flags
LDFLAGS += -mthumb -mabi=aapcs -L $(TEMPLATE_PATH) -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker to dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs -lc -lnosys







.PHONY: $(TARGETS) default all clean help flash 
# Default target - first one defined
default: nrf52832_xxaa

# Print all targets that can be built
help:
	@echo following targets are available:
	@echo 	nrf52832_xxaa

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc

include $(TEMPLATE_PATH)/Makefile.common
$(foreach target, $(TARGETS), $(call define_target, $(target)))
-include $(foreach target, $(TARGETS), $($(target)_dependencies))

# Flash the program
flash: $(OUTPUT_DIRECTORY)/nrf52832_xxaa.hex
	@echo Flashing: $<
	nrfjprog --program $< -f nrf52 --chiperase
	nrfjprog --reset -f nrf52

