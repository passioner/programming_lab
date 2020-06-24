define my-dir
$(strip \
$(eval LOCAL_MODULE_MAKEFILE := $$(lastword $$(MAKEFILE_LIST))) \
$(patsubst %/, %, $(dir $(LOCAL_MODULE_MAKEFILE))) \
)
endef

define gen-intermediates-dir
$(strip $(addprefix $(TOPDIR)/,$(subst ../,$(DOTDOT_REPLACEMENT),$(LOCAL_PATH))))
endef

define transform-c-to-o
mkdir -p $(dir $@)
$(CC) -c $(PRIVATE_GLOBAL_CFLAGS) $(PRIVATE_CFLAGS) -D__FILE_NAME__='$(patsubst %.c,%,$(notdir $<))' $< -o $@
endef
