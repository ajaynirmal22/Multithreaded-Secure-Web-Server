#include "import_st.h"

void jpeg_handler(int socket, char *file_name)
{
    char *buffer;
    char *full_path = (char *)malloc((strlen(PATH) + strlen(file_name)) * sizeof(char));
    int fp;

    strcpy(full_path, PATH); // Merge the file name that requested and path of the root folder
    strcat(full_path, file_name);
    puts(full_path);

    if ((fp=open(full_path, O_RDONLY)) > 0) //FILE FOUND
    {
        puts("Image Found.");
        int bytes;
        char buffer[BUFFER_SIZE];

        send(socket, success_200_jpeg, 45, 0);
	    while ( (bytes=read(fp, buffer, BUFFER_SIZE))>0 ) // Read the file to buffer. If not the end of the file, then continue reading the file
			write (socket, buffer, bytes); // Send the part of the jpeg to client.
    }
    else // If there is not such a file.
    {
        write(socket, error_404_notfound, strlen(error_404_notfound));
    }

    free(full_path);
    close(fp);
}

void get_data(int sock, char *username)
{
    	char *command;
	//executing ls command
	
	strcpy(command, "python3 scrape.py ");
	strcat(command,username);
	//puts(command);
	printf("Getting Results from Twitter...\n");
	system(command);
}

void get_csv(int socket, char *file_name)
{
    char *buffer;
    char *full_path = (char *)malloc((strlen(PATH) + strlen(file_name)) * sizeof(char));
    int fp;
    long bytes;
    strcpy(full_path, "./tweets"); // Merge the file name that requested and path of the root folder
    strcat(full_path, file_name);

    fp = open(full_path, O_RDONLY);
    if (fp > 0) //FILE FOUND
    {
        puts("File Found.");

       
	char buffer[BUFFER_SIZE];
        send(socket, success_200_csv, 44, 0); // Send the header for succesful respond..
        while ( (bytes=read(fp,buffer, BUFFER_SIZE))>0 ) // Read the file to buffer. If not the end of the file, then continue reading the file
			write (socket, buffer, bytes); // Send the part of the jpeg to client.
        //buffer = (char *)malloc(bytes_read * sizeof(char)); 
        
        //fread(buffer, bytes_read, 1, fp); // Read the csv file to buffer.
        //write (socket, buffer, bytes_read); // Send the content of the html file to client.
        //free(buffer);
        
        close(fp);
    }
    else // If there is not such a file.
    {
        write(socket, error_404_notfound, strlen(error_404_notfound));
    }
    int status = remove(full_path);
    free(full_path);
}

void html_handler(int socket, char *file_name) // handle html files
{
    char *buffer;
    char *full_path = (char *)malloc((strlen(PATH) + strlen(file_name)) * sizeof(char));
    FILE *fp;

    strcpy(full_path, PATH); // Merge the file name that requested and path of the root folder
    strcat(full_path, file_name);

    fp = fopen(full_path, "r");
    if (fp != NULL) //FILE FOUND
    {
        puts("File Found.");

        fseek(fp, 0, SEEK_END); // Find the file size.
        long bytes_read = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        send(socket, success_200_html, 44, 0); // Send the header for succesful respond.
        buffer = (char *)malloc(bytes_read * sizeof(char)); 
        
        fread(buffer, bytes_read, 1, fp); // Read the html file to buffer.
        write (socket, buffer, bytes_read); // Send the content of the html file to client.
        free(buffer);
        
        fclose(fp);
    }
    else // If there is not such a file.
    {
        write(socket, error_404_notfound, strlen(error_404_notfound));
    }

    free(full_path);
}

int write_json(const char *json){
    static char filename[100] = "logs/ip_logging.json";
    static int packet_count = 0;	
    
    packet_count++;
    // create file if it doesn't exist
    FILE* fp = fopen(filename, "r");
    if (!fp)
    {
       fp = fopen(filename, "w");
       if (!fp)
           return 0;
       fputs("[]", fp);
       fclose(fp);
    }

    // add the document to the file
    fp = fopen(filename, "rb+");
    if (fp)
    {
       // check if first is [
       fseek(fp, 0, SEEK_SET);
       if (getc(fp) != '[')
       {
           fclose(fp);
          return 0;
       }

       // is array empty?
       int is_empty = 0;
       if (getc(fp) == ']')
           is_empty = 1;

      // check if last is ]
       fseek(fp, -1, SEEK_END);
       if (getc(fp) != ']')
       {
           fclose(fp);
           return 0;
       }


       // replace ] by ,
       fseek(fp, -1, SEEK_END);
       if (!is_empty)
           fputc(',', fp);

       // append the document
       fputs(json, fp);

       // close the array
       fputc(']', fp);
       fclose(fp);
       return 1;
   }
   return 0;
}

char *time_stamp(){

char *timestamp = (char *)malloc(sizeof(char) * 16);
time_t ltime;
ltime=time(NULL);
struct tm *tm;
tm=localtime(&ltime);

sprintf(timestamp,"%04d%02d%02d%02d%02d%02d", tm->tm_year+1900, tm->tm_mon, 
    tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
return timestamp;
}


