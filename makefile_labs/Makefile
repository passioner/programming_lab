.PHONY: all
DEFAULT_GOAL := all
$(DEFAULT_GOAL)

OUTFILE := myout

all_objs :=

subdirs :=
subdirs += app
subdirs += driver
subdirs += bsp
subdirs += kernel

subdir_makefile := $(shell python build/scripts/findMakefile.py $(subdirs) Makefile)
$(foreach mk, $(subdir_makefile), $(info including $(mk) ...)$(eval include $(mk)))

$(OUTFILE).elf : $(all_objs)
	mkdir -p $(dir @)
	$(CC) $(INCLUDE_DIRS) $^ -o $@
	$(OBJCOPY) $@ $(OUTFILE).img

all: $(OUTFILE).elf
	echo -e "\033[32m build success\033[0m"

.PHONY: clean
clean:
	rm -rf out
