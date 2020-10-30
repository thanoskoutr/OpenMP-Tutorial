CC=gcc
CFLAGS=-Wall -g -fopenmp

EXECUTABLES=hello pi pi_spmd_simple pi_spmd_final pi_loop mandel mandel_par linked linked_par linked_tasks

all: $(EXECUTABLES)

hello: hello.o
	$(CC) $(CFLAGS) -o $@ $<

pi: pi.o
	$(CC) $(CFLAGS) -o $@ $<

pi_spmd_simple: pi_spmd_simple.o
	$(CC) $(CFLAGS) -o $@ $<

pi_spmd_final: pi_spmd_final.o
	$(CC) $(CFLAGS) -o $@ $<

pi_loop: pi_loop.o
	$(CC) $(CFLAGS) -o $@ $<

mandel: mandel.o
	$(CC) $(CFLAGS) -o $@ $<

mandel_par: mandel_par.o
	$(CC) $(CFLAGS) -o $@ $<

linked: linked.o
	$(CC) $(CFLAGS) -o $@ $<

linked_par: linked_par.o
	$(CC) $(CFLAGS) -o $@ $<

linked_tasks: linked_tasks.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) *.o

distclean: clean
	$(RM) $(EXECUTABLES)

.c.o:
	$(CC) $(CFLAGS) -c $<
