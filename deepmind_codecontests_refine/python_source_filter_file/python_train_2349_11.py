a,b=map(int,input().split())
c=0;k=0;s='';
while a!=b and c==0 and b>a:
    if b%10==1:
        b=b//10
        s=s+'1'
    else:
        if b%2==1:
            c=1
        else:
            b=b//2
            s=s+'2'
    k+=1
if c==0 and b==a:
    print('YES')
    print(k+1)
    print(a,end=' ')
    for i in range(k):
        if int(s[len(s)-1-k])==1:
            print(a*10+1,end='')
            a=a*10+1
        else:
            print(a*2,end=' ')
            a=a*2
else:
    print('NO')