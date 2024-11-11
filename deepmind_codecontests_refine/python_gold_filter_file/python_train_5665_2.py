n=int(input())
x,y,c=0,0,0
for i in range(n):
    a,b=map(int,input().split(' '))
    if(a&1):
        x=(x+1)
    if(b&1):
        y=(y+1)
    if((a+b)&1):
        c=1
if(x&1==y&1 and (x&1==0 or c==1)):
    print(x&1)
else:
    print(-1)