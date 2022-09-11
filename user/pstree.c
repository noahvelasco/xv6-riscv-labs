#include "kernel/param.h"
#include "kernel/types.h"
#include "user/uproc.h"
#include "user/user.h"

void mktree(struct uproc *uproc, int nprocs, int indentation, int pid){
    if(nprocs != 0){
        struct uproc *u;
        //go through all processes and print them like a tree   
        for(u = uproc; u < &uproc[nprocs]; u++){
             //if we find specified pid then print then make call to its child    
            if (u->pid == pid){
                //print indentation
                int i;            
                for(i=0; i<indentation; i++){
                    printf("\t");
                }
                printf("%s(%d)\n", u->name, u->pid);
                struct uproc *k;
                for(k = uproc; k < &uproc[nprocs]; k++){
                    if(k->ppid == pid){
                        mktree(uproc, nprocs-1, indentation+1, k->pid);
                    } //inner if
                }//inner for
            }//if
        }//for
    }

}//mktree



int main(int argc, char **argv)

{
  struct uproc uproc[NPROC];
  int nprocs;
  nprocs = getprocs(uproc); //will return # of active processes

  if (nprocs < 0)

    exit(-1);
    
  // You can remove the following print statement
  printf("\n---------%d processes active------------\n", nprocs);
  
  mktree(uproc, nprocs, 0, 1); //starts with looking for init and indentation 0

//  printf("pid\tppid\tsize\tname\n");
//  struct uproc *u;
//  for(u = uproc; u < &uproc[nprocs]; u++){
//    printf("%d\t%d\t%d\t%s\n", u->pid, u->ppid,u->size, u->name);
//  }

  exit(0);

}


