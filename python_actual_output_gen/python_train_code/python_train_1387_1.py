n=int(input())
a=list(map(int,input().split()))
m=a[0];wid=0;len=0
for i in a:
    if i==m:
        wid+=1
    else:
        break
for i in a:
    if i==m:
        len+=1
    elif len!=wid:
        print('NO')
        exit(0)
    else:
        len=1
        if m==1:m=0
        else:m=1
if len!=m:
    print('NO')
else:
    print('YES')
    