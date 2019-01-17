int readcount,writecount;

void reader(){
    while(true){
        semWait(z);
            semWait(rsem);
                semWait(x)
                    readcount++;
                    if(readcount==1){
                        semWait(wsem);
                    }
                    semSignal(x);
                semSignal(rsem);
            semSignal(z);
            READUNIT();
            semWait(x);
                readcount--;
                if(readcount==0){
                    semSignal(wsem);
                }
                semSignal(x);
    }
}

void writer(){
    while(true){
        semWait(y);
            writecount++;
            if(writecount==1){
                semWait(rsem);
            }
            semSignal(y);
        semWait(wsem);
        WRITEUNIT();
        semWait(y);
            writecount--;
            if(writecount==0){
                semSignal(rsem);
            }
            semSignal(y);
    }
}









void main(){
    readcount=writecount=0;
    parbegin(reader,writer);
}