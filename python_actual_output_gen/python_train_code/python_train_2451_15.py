n,a,x,b,y=map(int,input().split())
flag=0
while a!=x and b!=y:
    a+=1
    b-=1
    if a==n+1:
        a=1
    if b==1:
        b=n
    if a==b:
        flag=1
        break
if flag==1:
    print('Yes')
else:
    print('No')