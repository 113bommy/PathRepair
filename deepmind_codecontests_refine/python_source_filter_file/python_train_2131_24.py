n=int (input())
cnt=0
n+=1
while (1):
    sn=str(n)
    f=0
    for i in sn:
        if (i=='8'):
            f=1
    if (f==1):
        print(cnt)
        break
    n+=1
    cnt+=1
