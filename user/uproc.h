enum uprocstate {UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE};

struct uproc{

    int pid; //pid
    enum uprocstate state; //process state
    uint64 size; //size of process memory 
    int ppid; //parent ID
    char name[16]; //Proess command name
    uint cputime;   //total amount of time this process has ran on cpu
}
