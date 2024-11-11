n=int(input())
ma=mg=0
s=''
for _ in ' '*n:
    x,y=map(int,input().split())
    if ma+x-mg<500:
        s+='A'
        ma+=x
    elif mg+y-ma<500:
        s+='G';mg+=y

if len(s)==n:
    print(s)
else:print(-1)