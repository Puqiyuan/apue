IDIR=include
CC=gcc
CFLAGS1=-I $(IDIR)
CHAPTER2CODES=chapter2/example_programs
CHAPTER3CODES=chapter3/example_programs

BIN=bin

ODIR=obj
LDIR=lib

LIBS=-lapue
CFLAGS2=-L $(LDIR)
.SECONDARY: $(OBJS)
all: $(BIN)/p81 $(BIN)/p85 $(BIN)/p86 $(BIN)/p101 $(BIN)/p102 $(BIN)/p106

_DEPS = apue.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))


$(ODIR)/%.o: $(CHAPTER2CODES)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS1)

$(ODIR)/%.o: $(CHAPTER3CODES)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS1)

$(BIN)/%: $(ODIR)/%.o
	gcc -o $@ $^ $(CFLAGS2) $(LIBS)

clean:
	rm -f $(BIN)/* && rm -f $(ODIR)/*


