CC = gcc
CFLAGS = -W -Wall -O2
LDFLAGS = -lm

all : main getFileSystemsInfo getFilePointFromPopen		
		$(CC) $(CFLAGS) -o main main.o getFileSystemsInfo.o getFilePointFromPopen.o $(LDFLAGS)
main : main.c
		$(CC) $(CFLAGS) -c main.c

getFileSystemsInfo : getFileSystemsInfo.c
		$(CC) $(CFLAGS) -c getFileSystemsInfo.c

getFilePointFromPopen : getFilePointFromPopen.c
		$(CC) $(CFLAGS) -c getFilePointFromPopen.c

clean  :
		@rm -rf *.o main *~
