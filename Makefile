snake: compile run

compile:
	g++ main.cpp snake.cpp -o bin/snake

run:
	bin/snake