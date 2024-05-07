# Files in C

#### Different modes for opening files:

1. `O_CREAT`: Operation Create.
2. `O_WRONLY`: Operation Write Only. (Clears file before writing)
3. `O_RDWD`: Operation Read/Write.
4. `O_RDONLY`: Operation Read Only.
5. `O_APPEND`: Operation Append. (If data exists append to the file)

#### Functions:

1. `open()`: Open a file.
2. `read()`: Read from a file.
3. `write()`: Write to a file.
4. `lseek()`: Move the read/write pointer ahead.
5. `close()`: Close an opened file.


#### Permission settings:

1. `0644`: Owner can read and write the file, others can only read.
2. `0666`: Everyone can read and write the file.
3. `0700`: Owner can read, write and execute the file.
4. `0777`: Everyone can read, write and execute the file. 

#### Seek Settings

1. `SEEK_SET`: Set pointer relative to start.
2. `SEEK_END`: Set pointer relative to end.
3. `SEEK_CUR`: Set pointer relative to current position.

