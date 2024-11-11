n=int(input())
ans=1
x,y=0,0
for i in range(n):
    a,b=map(int,input().split())
    if(x!=a or y!=b):
        ans+= max(0,(min(a,b)-max(x,y)-(x==y)+1))
    x=a
    y=b
print(max(ans,1))