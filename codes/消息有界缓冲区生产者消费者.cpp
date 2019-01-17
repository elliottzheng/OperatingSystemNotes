const int capacity=N,// 代表了缓冲区容量
null=//空消息
int i;

void producer(){
    message pmsg;
    while(true){
        receive(mayproduce,pmsg);
        pmsg=produce();
        send(mayconsume,pmsg);
    }
}

void consumer(){
    message cmsg;
    while(true){
        receive(mayconsume,cmsg);
        consume(cmsg);
        send(mayproduce,null);
    }
}



void main(){
    create_mailbox(mayconsume);
    create_mailbox(mayproduce);
    for(int i=0;i<capacity;i++){ //先填充空消息，空消息个数就是缓冲区容量。
        send(mayproduce,null);
    }
    parbegin(producer,consumer);
}