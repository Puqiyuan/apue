IDIR=include
CC=gcc
CFLAGS1=-I $(IDIR)
CHAPTER2CODES=chapter2/example_programs
CHAPTER3CODES=chapter3/example_programs
CHAPTER4CODES=chapter4/example_programs
CHAPTER7CODES=chapter7/example_programs
CHAPTER8CODES=chapter8/example_programs

BIN=bin

ODIR=obj
LDIR=lib

LIBS=-lapue
CFLAGS2=-L $(LDIR)
.SECONDARY: $(OBJS)
all: $(BIN)/p81 $(BIN)/p85 $(BIN)/p86 $(BIN)/p101 $(BIN)/p102 $(BIN)/p106 $(BIN)/p118 $(BIN)/p130 $(BIN)/p137 $(BIN)/p138 $(BIN)/p141 $(BIN)/7.13 $(BIN)/7.16 $(BIN)/8.8 $(BIN)/8.12


_DEPS = apue.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))


$(ODIR)/%.o: $(CHAPTER2CODES)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS1)

$(ODIR)/%.o: $(CHAPTER3CODES)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS1)

$(ODIR)/%.o: $(CHAPTER4CODES)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS1)

$(ODIR)/%.o: $(CHAPTER7CODES)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS1)

$(ODIR)/%.o: $(CHAPTER8CODES)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS1)

$(BIN)/%: $(ODIR)/%.o
	gcc -o $@ $^ $(CFLAGS2) $(LIBS)

clean:
	rm -f $(BIN)/* && rm -f $(ODIR)/*


