CC = gcc

REC = message_rec
SND = message_send

COMMON = common.o

all: $(REC) $(SND)

$(REC):
	$(CC) -o $(REC) $(REC).c

$(SND): $(COMMON) 
	$(CC) -o $(SND) $(COMMON) $(SND).c 

clean:
	rm -rf *.o a.out $(REC) $(SND)

