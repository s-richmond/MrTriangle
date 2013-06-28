install: main.c
	gcc -Wall  main.c -o runtime -lglfw -lGL 
clean:
	rm runtime
