CC = gcc

REC = message_rec
SND = message_send

all: $(REC) $(SND)

$(REC):
	$(CC) -o $(REC) $(REC).c

$(SND):
	$(CC) -o $(SND) $(SND).c

clean:
	rm -rf *.o a.out $(REC) $(SND)

