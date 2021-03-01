
all:client server

client:tcp_client.h testing_client.cpp
	g++ testing_client.cpp -o client
server:tcp_client.h testing_server.cpp
	g++ testing_server.cpp -o server

test: all
	./server | ./client


clean:
	rm client server
