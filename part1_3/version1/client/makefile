
all:client server

all2: client2 server2

client2: testing_server2.cpp tcp_client.h
	g++ -g testing_client2.cpp -o client2

server2: testing_server2.cpp tcp_client.h
	g++ -g testing_server2.cpp -o server2

client:tcp_client.h testing_client.cpp
	g++ -g testing_client.cpp -o client
server:tcp_client.h testing_server.cpp
	g++ -g testing_server.cpp -o server

test: all
	./server >test.txt | ./client


clean:
	rm client server client2 server2
