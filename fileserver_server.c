/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "fileserver.h"


char* get_pathname(filename name) {
    char *pathname = (char *)malloc((strlen(FOLDER_SERVER) + strlen(name)) * sizeof(char));
    sprintf(pathname, "%s%s", FOLDER_SERVER, name);
    return pathname;
}

bool_t
read_1_svc(filename name, int position, int cant, filedata *result,  struct svc_req *rqstp)
{
    bool_t retval = 1;
    char *pathname = get_pathname(name);
    FILE *file = fopen(pathname, "rb");
    if (file != NULL)
    {
        fseek(file, position, SEEK_SET);
        result->filedata_val =  (char *)calloc(cant, sizeof(char));
        result->filedata_len = fread(result->filedata_val, sizeof(char), cant, file);
        fclose(file);
    } else {
        fprintf(stderr, "%s", "File Not Found!\n");
        result->filedata_len = -1;
        result->filedata_val = (char *) NULL;
    }
    free(pathname);
    return retval;

}

bool_t
write_1_svc(filename name, filedata data, int *result,  struct svc_req *rqstp)
{
    bool_t retval = 1;
    char *pathname = get_pathname(name);
    FILE *file = fopen(pathname, "ab");
    *result = fwrite(data.filedata_val, sizeof(char), data.filedata_len, file);
    fclose(file);
    free(pathname);
    return retval;
}

bool_t
size_1_svc(filename name, int *result,  struct svc_req *rqstp)
{
    bool_t retval = 1;

    char *pathname = get_pathname(name);
    // opening the file in read mode
    FILE* file = fopen(pathname, "rb");
    // checking if the file exist or not
    if (file == NULL) {
        fprintf(stderr, "%s", "File Not Found!\n");
        *result = -1;
    } else {
        fseek(file, 0L, SEEK_END);
        // calculating the size of the file
        *result = (int)ftell(file);
        // closing the file
        fclose(file);
    }
    free(pathname);

    return retval;
}

int
fileserver_program_1_freeresult (SVCXPRT *transp, xdrproc_t xdr_result, caddr_t result)
{
    xdr_free (xdr_result, result);

    /*
     * Insert additional freeing code here, if needed
     */

    return 1;
}
