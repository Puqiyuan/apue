IDIR=include
CC=gcc
CFLAGS1=-I $(IDIR)
CHAPTER2=chapter2
BIN=bin
CURRENT=APUE

ODIR=obj
LDIR=lib

LIBS=-lapue
CFLAGS2=-L $(LDIR)
.SECONDARY: $(OBJS)
all: $(BIN)/p81 $(BIN)/p85 $(BIN)/p86

_DEPS = apue.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))


$(ODIR)/%.o: $(CHAPTER2)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS1)

$(BIN)/%: $(ODIR)/%.o
	gcc -o $@ $^ $(CFLAGS2) $(LIBS)

clean:
	rm -f $(BIN)/* && rm -f $(ODIR)/*


