

all:server client server_marshal.h client_marshal.h
	echo Testing the client

server:server.cpp server_marshal.h
	g++ server.cpp -o server

client:client.cpp client_marshal.h
	g++ client.cpp -o client

test_server: server server.cpp server_marshal.h
	@./server "START 2"
	@./server "CHOICE 5"
	@./server "END 1"
	@./server "ERROR 2"
	@./server "USER" " Enter your Username: " "2" " 1. Option 1 " " 2. Option 2 "
	@./server "PASS" "Enter your password: " "2" " 1. Option 1 " " 2. Option 2 "
	@./server "ERROR" "You have an error " "2" " 1. Option 1 " " 2. Option 2 "
	@./server "END" "Ending Connection" "2" " 1. Option 1 " " 2. Option 2 "
	@./server "LIST" "This are the options" "3" " 1. Option 1 " " 2. Option 2 " " 3. Option 3 "
	@./server "LIST" "This are the options" "2" " 1. Option 1 " " 2. Option 2 "
	@./server "LIST" "This are the options" "2" " 1. Option 1 "





test_client: client client.cpp client_marshal.h
	@./client "USER Enter Your Username:"
	@./client "PASS Enter your Password:"
	@./client "ERROR There is an Error:"
	@./client "END Ending the Connection"
	@./client "LIST Here are the options: \ 1 1.Option 1 \\"
	@./client "LIST Here are the options: \ 2 1.Option 1 \ 2. Option 2 \\"
	@./client "LIST Here are the options: \ 3 1.Option 1 \ 2. Option 2 \ 3. Option 3 \\"
	@./client "LIST Here are the options: \ 4 1.Option 1 \ 2. Option 2 \ 3. Option 3 \ 4. Option 4 \\"
	@ echo
	@ echo
	@./client "START" "1"
	@./client "CHOICE" "1"
	@./client "END" "1"
	@./client "ERROR" "1"
clean:
	rm server client


