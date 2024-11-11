n=int(input())
l=list(map(int,input().split()))
s=sum(l)
x,y=0,0
for i in range(n):
    if(l[i]%2==1):
        x=x+1
    else:
        y=y+1
if(s%2==0):
    print(x)
else:
    print(y)