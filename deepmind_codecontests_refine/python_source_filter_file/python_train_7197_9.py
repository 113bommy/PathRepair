n=int(input())
x,y=map(int,input().split())
if x==0 or y==0:
    ans=1
else:
    ans=min(x,y)+1
for i in range(n-1):
    a,b=map(int,input().split())
    if x>y:
        if b>x:
            ans+=min(b,a)-x+1
        if b==x and b!=y:
            a+=1
    elif y>x:
        if a>y:
            ans+=min(b,a)-y+1
        if a==y and a!=x:
            ans+=1
    else:
        ans+=min(a,b)-x
    x,y=a,b
print(ans)
