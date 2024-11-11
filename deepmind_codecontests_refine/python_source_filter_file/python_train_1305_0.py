inp = list(map(int,input().split()))
a=inp[0]
b=inp[1]
c=inp[2]
if(c==0):
    if(a==b):
        print('YES')
    else:
        print('NO')
else:
    if((b-a)%c==0 and ((b-a)//c)>0):
        print('YES')
    else:
        print('NO')