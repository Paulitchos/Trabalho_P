all:
	@gcc ./src/*.c -o ./dist/main  -lm && ./dist/main
	
