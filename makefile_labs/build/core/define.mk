define my-dir
$(strip \
$(eval LOCAL_MODULE_MAKEFILE := $$(lastword $$(MAKEFILE_LIST))) \
$(patsubst %/, %, $(dir $(LOCAL_MODULE_MAKEFILE))) \
)
endef

define gen-intermediates-dir
$(strip $(addprefix $(OUTDIR)/, $(subst ../, $(DOTDOT_REPLACEMENT), $(LOCAL_PATH))))
endef

define transform-c-to-o
$(Q)mkdir -p $(dir $@)
$(CC) -c $(PRIVATE_GLOBAL_CFLAGS) $(PRIVATE_CFLAGS) $< -o $@
endef
