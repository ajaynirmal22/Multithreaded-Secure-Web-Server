
char* error_400_busy = "HTTP/1.0 400 Bad Request\r\nContent-Type: text/html\r\n\r\n<!doctype html><html><body>System is busy right now.</body></html>";
char* error_400_bad = "HTTP/1.0 400 Bad Request\r\nConnection: close\r\nContent-Type: text/html\r\n\r\n<!doctype html><html><body>400 Bad Request</body></html>";
char* error_400_filetype = "HTTP/1.0 400 Bad Request\r\nConnection: close\r\n\r\n<!doctype html><html><body>400 Bad Request. (You need to request html files)</body></html>";
char* success_200_jpeg = "HTTP/1.0 200 OK\r\nContent-Type: image/jpeg\r\n\r\n";
char* success_200_html = "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n";
char* success_200_csv = "HTTP/1.0 200 OK\r\nContent-Type: text/csv\r\n\r\n";
char* success_200_get_data = "HTTP/1.0 200 OK\r\n";
char* error_404_notfound = "HTTP/1.0 404 Not Found\r\nConnection: close\r\nContent-Type: text/html\r\n\r\n<!doctype html><html><body>404 File Not Found</body></html>";
