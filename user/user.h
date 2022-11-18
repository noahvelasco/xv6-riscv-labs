#define NULL 0

;struct stat;
struct rtcdate;
struct uproc;
struct rusage;
struct buffer_t;

// system calls
int fork(void);
int exit(int) __attribute__((noreturn));
int wait(int*);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);

// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void fprintf(int, const char*, ...);
void printf(const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
int memcmp(const void *, const void *, uint);
void *memcpy(void *, const void *, uint);

//prototype
int getprocs(struct uproc*);
int wait2(int*, struct rusage*); //just like wait but 1 more param
int freepmem(void);
void *mmap(void*, uint64, int,int,int,int);
int munmap(void*, int);

//lab 4
int sem_init(sem_t sem*, int, uint);
int sem_destroy(sem_t sem*);
int sem_wait(sem_t sem*);
int sem_post(sem_t sem*);



