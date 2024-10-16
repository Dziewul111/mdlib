
xd(){
  g++-14 -Wall -Wshadow -Wextra -Wfloat-equal -std=c++20 -o $1 -O3 $1.cpp -D_GLIBCXX_DEBUG
}

xdd(){
	g++-14 -Wall -Wshadow -Wextra -Wfloat-equal -std=c++20 -0 $1 -O3 $1.cpp -D_GLIBCXX_DEBUG -DDEBUG
}