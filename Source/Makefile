CC=g++
CFLAGS=-I.
DEPS = Team.h Spread.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Main: Team.o Spread.o Main.o 
	$(CC) -o predict Team.o Spread.o Main.o

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
