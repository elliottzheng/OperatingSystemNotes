void reader(){
    message msg;
    while(true){
        rmsg=i;
        send(readrequest,msg);
        receive(mbox[i],rmsg);
        READUNIT();
        rmsg=i;
        send(finished,rmsg);
    }
}
void writer(){
    message rmsg;
    while(true){
        rmsg=j;
        send(writerequest,rmsg);
        receive(mbox[i],rmsg);
        WRITEUNIT();
        rmsg=j;
        send(finished,rmsg);
    }
}


void controller(){
    while(true){
        if(count>0){
            if(!empty(finished)){
                receive(finished,msg);
                count++;
            }else if(!empty(writerequest)){
                receive(writerequest,msg);
                writer_id=msg.id;
                count=count-100;
            }
            else if(!empty(readrequest)){
                receive(readrequest,msg);
                count--;
                send(msg.id,"OK");
            }
        }
        if(count==0){
            send(writer_id,"OK");
            receive(finished,msg);
            count=100;
        }
        while(count<0){
            receive(finished,msg);
            count++;
        }
    }
}