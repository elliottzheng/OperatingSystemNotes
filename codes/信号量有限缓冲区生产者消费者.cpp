const int sizeofbuffer=N//缓冲区大小
semaphore n=0,s=1,e=sizeofbuffer; //n是缓冲区可用项数，s是缓冲区访问权限

void producer(){
    while(true){
        produce();//不管三七二十一反正先生产，能不能放再说
        semWait(e);
        semWait(s);
        append();
        semSignal(s);
        semSignal(n); //这两个位置互换没事，但是
    
    }
}

void consumer(){
    while(true){
        semWait(n); //这两个Semwait不能互换，因为缓冲区为空的时候绝对不能让消费者占用缓冲区访问权限，到时候就会死锁了
        semWait(s);
        take();
        semSignal(e);
        semSignal(s);
        consume();
    }
}