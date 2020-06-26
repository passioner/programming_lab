subdirs += app
subdirs += driver
subdirs += bsp
subdirs += kernel

INCLUDE_DIRS += include
INCLUDE_DIRS += include/app
INCLUDE_DIRS += include/app/app_1

INCLUDE_DIRS := $(addprefix -I, $(INCLUDE_DIRS))

GLOBAL_CFLAGS += $(INCLUDE_DIRS)

ifneq ($(strip $(exclude_dirs)),)
	$(exclude_dirs) := $(addprefix --exclude_dirs , $(exclude_dirs))
endif
