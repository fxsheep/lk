LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_DEPS += \
    lib/cbuf \

MODULE_SRCS += \
	$(LOCAL_DIR)/platform.c \
	$(LOCAL_DIR)/timer.c \
#	$(LOCAL_DIR)/uart.c \

ARCH := arm
ARM_CPU := cortex-r5
MEMBASE := 0x20000000
MEMSIZE := 0x180000	# 1.5MB
WITH_KERNEL_VM = 0
KERNEL_BASE := 0x20000000 
KERNEL_LOAD_OFFSET := 0x000C0000
LINKER_SCRIPT += \
	$(BUILDDIR)/system-onesegment.ld

MODULE := $(LOCAL_DIR)

MODULE_DEPS += \
		app/shell \


include make/module.mk
