
CC = gcc
CFLAGS = -g 

CN = client
SR = serv
UCN = udpclient
USR = udpserver

LIBS = tcp.o udp.o

all: $(CN) $(SR) $(UCN) $(USR)

$(CN): $(LIBS)
	$(CC) -o $(CN) $(CFLAGS) $(LIBS) $(CN).c 

$(SR): $(LIBS)
	$(CC) -o $(SR) $(CFLAGS) $(LIBS) $(SR).c 

$(UCN): $(LIBS)
	$(CC) -o $(UCN) $(CFLAGS) $(LIBS) $(UCN).c 

$(USR): $(LIBS)
	$(CC) -o $(USR) $(CFLAGS) $(LIBS) $(USR).c 

clean: 
	rm -rf $(CN) $(SR) $(UCN) $(USR) *.dSYM *.o
