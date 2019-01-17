const int n=N; //进程数
void P(int i){
    message msg;
    while(true){
        receive(box,msg);
    }
    send(box,msg);
}

void main(){
    create_mailbox(box);
    send(box,null); //可以认为这一条消息是一个令牌
    parbegin(P(1),P(2),...,p(n));
}