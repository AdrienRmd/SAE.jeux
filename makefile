CC = gcc
CFLAGS = -Wall -Wextra -g
EXEC = neo_terra
OBJ = main.o function/file_manipulation.o function/other.o function/gamef.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)