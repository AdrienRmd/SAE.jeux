CC = gcc
CFLAGS = -Wall -Wextra -g
EXEC = the_final_dawn
OBJ = main.o function/file_manipulation.o function/other.o function/gamef.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)