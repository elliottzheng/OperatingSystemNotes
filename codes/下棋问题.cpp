//先抢到棋盘者先下，然后轮流下子
turn=0;
//0表示还不知道是谁的回合，只需要把turn的初始化的值改一下就可以了,虽然效率不高，但是怎么说，算法是没问题的
semaphore m=1; //棋盘访问控制信号量
void black(){
    while(notend){
        semWait(m);
        if (turn<>2) //不是对方回合
        {
            down();
            turn=2;
        }
        semSignal(m);
    }
}

void white(){
    while(notend){
        semWait(m);
        if (turn<>1) //不是对方回合，就可以直接拿过来作为自己回合下棋
        {
            down();
            turn=1;
        }
        semSignal(m);
    }
}

