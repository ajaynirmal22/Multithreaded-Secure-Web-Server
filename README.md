# PCS-2 Secure Multi-threaded Web Server
Course Project "Secure-Multithreaded-Web-Server" | Principles of Computer Systems-II

# Requirements
1. gcc compiler | gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1) 

# Usage | Follow these steps to use this repo
1. Extract the Zip file downloaded.
2. Open a terminal window in that folder
3. Run the command (`git clone --depth=1 https://github.com/twintproject/twint.git`)
4. Run the command (`cd twint`) | Going inside the newly created twint folder
5. Run the command (`pip3 install . -r requirements.txt`)
6. Run the command (`cd ..`) | Going back to the main project folder
7. [optional] Run the command (`gcc -pthread server.c -o server.o`) 
8. Run the command (`chmod +x ./server.o`)
9. Run the command (`./server.o [port no]`).
        port no. refers to the port numnber you want ot run the server on. For ex. (`./server.o 8080`)
10. Open a browser window and load the url (`localhost:[port no]/index.html`)
11. Enter semi-colon separated twitter handels in the input box given and hit submit
12. If every step was successful, you'll get a done pop up, and the *tweets.csv* file will get downloaded for usage.

_________ END __________
