Execute: memoObject calendarObject mainObject
	gcc -o ExecuteDaily memo.o calendar.o main.o
memoObject:
	gcc -c -o memo.o memo.c	
calendarObject:
	gcc -c -o calendar.o calendar.c	
mainObject: main.c
	gcc -c -o main.o main.c			
clean:
	rm *.o ExecuteDaily
