.PHONY: all
.DEFAULT_GOAL := all

subdir_makefile := $(shell python build/scripts/findMakefile.py $(exclude_dirs) $(subdirs) Makefile)
$(foreach mk, $(subdir_makefile), $(info including $(mk) ...)$(eval include $(mk)))

$(OUTFILE).elf : $(all_objs)
	$(Q)mkdir -p $(dir $@)
	$(CC) $(INCLUDE_DIRS) $^ -o $@
	$(OBJCOPY) $@ $(OUTFILE).img

all: $(OUTFILE).elf
	$(Q)echo "\033[32m build success\033[0m"

.PHONY: clean
clean:
	$(Q)rm -rf $(OUTDIR)
	$(Q) echo "---make clean finished---"
