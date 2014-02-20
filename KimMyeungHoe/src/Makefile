CC = gcc
CFLAGS = -W -Wall -O2
LDFLAGS = -lm

all : Main GetFileSystemsInfo GetFilePointFromPopen		
		$(CC) $(CFLAGS) -o Main Main.o GetFileSystemInfo.o GetFilePoint.o $(LDFLAGS)
Main : Main.c
		$(CC) $(CFLAGS) -c Main.c

GetFileSystemsInfo : GetFileSystemInfo.c
		$(CC) $(CFLAGS) -c GetFileSystemInfo.c

GetFilePointFromPopen : GetFilePoint.c
		$(CC) $(CFLAGS) -c GetFilePoint.c

clean  :
		@rm -rf *.o Main *~
