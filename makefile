.SUFFIXES: .c .o

CC=gcc


SRCS=server.c\
		pub.c\
		work.c\
		doClassification.c\

		
OBJS=$(SRCS:.c=.o)
EXEC=myhttpd

all: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -lpthread
	@echo '-------------ok--------------'

.c.o: $(DBSRCS)
	$(CC) -Wall -g -o $@ -c $<
	
clean:
	rm -f $(OBJS)
	rm -f core*

