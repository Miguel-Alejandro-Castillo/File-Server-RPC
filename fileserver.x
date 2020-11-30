
typedef opaque filedata<>;
typedef string filename<>;

program FILESERVER_PROGRAM { 
  version FILESERVER_VERSION {
    filedata read(filename, int position, int cant) = 1;
    int write(filename, filedata) = 2;
    int size(filename) = 3;
  } = 1;
} = 0x20000001;