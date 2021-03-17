all:server  server_marshal.h
	echo Testing the client

server:server.cpp server_marshal.h
	g++ server.cpp -o server

server2:server2.cpp server_marshal.h
	g++ server2.cpp -o server2
test_server: server server.cpp server_marshal.h
	@./server "START 2"
	@./server "CHOICE 5"
	@./server "END 1"
	@./server "ERROR 2"
	@./server "USER" " Enter your Username: "
	@./server "PASS" "Enter your password: "
	@./server "ERROR" "You have an error "
	@./server "END" "Ending Connection"
	@./server "LIST" "This are the options" "3" " 1. Option 1 " " 2. Option 2 " " 3. Option 3 "
	@./server "LIST" "This are the options" "2" " 1. Option 1 " " 2. Option 2 "
	@./server "LIST" "This are the options" "1" " 1. Option 1 "
clean:
	rm server server2

