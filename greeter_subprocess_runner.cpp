#include "greeter_subprocess_runner.h"

greeter_subprocess_runner::greeter_subprocess_runner(QObject *parent) : QObject(parent)
{

}
static void handler_sig(int signum){
    printf("EXIT");
    QCoreApplication::exit(0);
}
static void detach_children(){
    struct sigaction act;
    act.sa_handler=handler_sig;
    sigemptyset(&act.sa_mask);
    act.sa_flags=SA_RESTART | SA_NOCLDWAIT;
    if(sigaction(SIGCHLD,&act,NULL) < 0){
        perror("err sigaction");
    }


}
void greeter_subprocess_runner::run(){
    //running subprocess
    //std::cout << "tintin" << std::endl;
    detach_children();
    pid_t pid=fork();
    if(pid < 0){
        perror("error fork");
        QCoreApplication::exit(-1);
    }else if(pid == 0){
        //child process
        execlp("vlc","vlc",NULL); //test
        perror("execlp");
        QCoreApplication::exit(-2);
    }
    // parent
    /*int status;
    if(waitpid(pid,&status,0) < 0){
        perror("waitpid");
        QCoreApplication::exit(0);
    }
    QCoreApplication::exit(0);
    */
}
