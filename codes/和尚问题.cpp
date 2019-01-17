semaphore bucket=3,empty=10,water=0,s_well=1,s_gang=1;//


void smallMonk(){//小和尚打水
    while(true){
        semWait(empty);
        semWait(bucket);
        semWait(s_well);
        getWater();
        semSignal(s_well);
        semWait(s_gang);
        pourWater();
        semSignal(s_gang);
        semSignal(water);
        semSignal(bucket);
    }
}

void oldMonk(){//老和尚喝水
    while(true){
        semWait(water);
        semWait(bucket);
        semWait(s_gang);
        takeWater();
        semSignal(s_gang);
        semSignal(empty);
        semSignal(bucket);
        drinkWater();
    }
}
