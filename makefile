compile:
	g++ -Wall -Wshadow -Wextra -static -Wfloat-equal -std=c++20 -o $(p) -O3 $(p).cpp -D_GLIBCXX_DEBUG
