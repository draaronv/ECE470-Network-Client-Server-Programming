all: client server

client: tcp_client2.h testing_client.cpp
	g++ -g testing_client.cpp -o client

server:	tcp_server2.h testing_server.cpp
	g++ -g testing_server.cpp -o server

all2: client server

client2: tcp_client2.h testing_client2.cpp
	g++ -g testing_client2.cpp -o client2

server2:	tcp_server2.h testing_server2.cpp
	g++ -g testing_server2.cpp -o server2

test_server: server
	./server
test_client: client
	./client

test_server2: server2
	./server2
test_client2: client2
	./client2


clean:
	rm server client server2 client2
