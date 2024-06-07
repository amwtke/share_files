CC = gcc
source = world.c func.c
#objects := $(wildcard *.o)
objects = world.o func.o
world:$(objects)
	$(CC) -o world $(objects)

include $(source:.c=.d)
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -M  $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

#world.o: world.c
#	$(CC) -c world.c
.PHONY : clean run
clean :
	rm -f world 
	rm -f *.o
	rm -f *.d
run:
	./world
