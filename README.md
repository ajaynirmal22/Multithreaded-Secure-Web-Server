# PCS-2 Secure Multi-threaded Web Server
Course Project "Secure-Multithreaded-Web-Server" | Principles of Computer Systems-II

# Requirements
1. Microsoft Visual C++ 14.0 or greater (for wordcloud)
2. Git (for cloning repo; installing twint;)
3. Virtual Environment (virtualenv) [optional] 

# Usage | Follow these steps to use this report
1. [optional] Run the command (`gcc -pthread server.c -o server.o`) 
2. Run the command (`chmod +x ./server.o`)
3. Run the command (`./server.o [port no]`)
        port no. referss to the port numnber you want ot run the server on. For ex. (`./server.o 8080`)

# Observations
1. Executing run.py will result in:-
    1.  Creating and exporting TfIdf Vectorizer Object in "saved_model/vectorzier/" 
    2.  Training and exporting 6 Logistic Regression Models (for 6 labels being used) in "saved_model/"

# Flask Web Framework | Get real time results on texual comments
## Usage
1. Run the commmand (`python api/server.py`)
    1. This will run the Flask API at localhost:5000
    2. You can use this API for two purposes:-
        1. Predicting toxicity and other label's levels for a single/multiple comments, given as an input by a user 
        2. Predicting toxicity and other label's levels across various Tweets of a Twitter user (input from a user) and classifying them as a toxic publisher or non toxic publisher

# EDA | Exploratory Data Analysis

# Data Preprocessing

# Training

# Testing

# Validation
