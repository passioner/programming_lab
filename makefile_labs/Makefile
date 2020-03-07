out := xxx
src := a.c
obj := a.o

all: $(out)

$(obj): $(src)
	gcc -c $< -o $@
$(out): $(obj)
	gcc $< -o $@
