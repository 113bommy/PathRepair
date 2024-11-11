t,m=map(int,input().split())
M=[0]*m
Cnt=0
for i in range(t):
    exp=input()
    if exp[0]=='a':
        v=int(exp[6:])
        cnt=0
        ok=False
        lock=False
        begin=0
        for I in range(m):
            if M[I]==0:
                if lock:
                    cnt+=1
                    if cnt>=v:
                        Cnt+=1
                        for j in range(begin,I+1):
                            M[j]=Cnt
                            ok=True
                        print(Cnt)
                        break
                else:
                    lock=True
                    cnt=1
                    begin=I
                    if cnt>=v:
                        Cnt+=1
                        for j in range(begin,I+1):
                            M[j]=Cnt
                            ok=True
                        print(Cnt)
                        break
            else:
                lock=False
                cnt=0
                begin=0
        if not ok:
            print('NULL')
    elif exp[0]=='e':
        ok=False
        v=int(exp[6:])
        for I in range(m):
            if M[I]==v:
                M[I]=0
                ok=True
        if not ok or v==0:
            print('ILLEGAL_ERASE_ARGUMENT')
    else:
        tmp=0
        for I in range(m):
            if M[I]!=0:
                M[tmp]=M[I]
                tmp+=1
        for I in range(tmp,m):
            M[I]=0
