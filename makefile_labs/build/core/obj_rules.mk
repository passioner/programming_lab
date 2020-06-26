intermediates := $(call gen-intermediates-dir)

my_src_files := $(LOCAL_FILES_y)
my_cflags := $(LOCAL_CFLAGS)

c_normal_files := $(filter-out ../%, $(filter %.c, $(my_src_files)))
c_normal_objs := $(addprefix $(intermediates)/, $(c_normal_files:.c=.o))

ifneq ($(strip $(c_normal_objs)),)
$(c_normal_objs): PRIVATE_GLOBAL_CFLAGS := $(GLOBAL_CFLAGS)
$(c_normal_objs): PRIVATE_CFLAGS := $(my_cflags)
$(c_normal_objs): $(intermediates)/%.o:$(TOPDIR)/$(LOCAL_PATH)/%.c $(my_extra_deps)
	$(transform-c-to-o)
endif

all_objs += $(c_normal_objs)
