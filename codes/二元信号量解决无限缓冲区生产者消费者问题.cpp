int n;
binary_semaphore s=1,delay=0;
void producer(){
  while(true){
    produce();//生产
    semWaitB(s); //获取缓冲区访问权限
    append();// 把所生产的产品放入缓冲区(临界资源)
    n++;
    if(n==1){ //说明在放置产品前，缓冲区没有产品，就有可能有消费者在没有产品的延迟队列上排队，因此需要用semSignalB去唤醒排队的消费者
      semSignalB(delay);
    }
    semSignalB(s);
  }
}
void consumer(){
  int m=0;
  semWaitB(delay); //等待生产出第一个产品
  while(true){
    semWaitB(s);
    take();
    n--;
    m=n;
    semSignalB(s);
    consume();
    if(m==0){ //没有资源，就等待
      semWaitB(delay);
    }
  }
}
void main(){
  n=0;
  parbegin(producer,consumer);
}
void main(){
  n=0;
  parbegin(producer,consumer);
}
