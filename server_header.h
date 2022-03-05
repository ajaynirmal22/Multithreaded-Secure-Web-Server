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
