CC      = gcc
CFLAGS  = -Wall -O2
LDFLAGS = 

OBJ = inodetest.o

all: inodetest

inodetest: $(OBJ)
	$(CC) $(CFLAGS) -o inodetest $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm inodetest *.o -f