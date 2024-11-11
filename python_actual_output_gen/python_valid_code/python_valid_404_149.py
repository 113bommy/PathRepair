a=int(input())
ans=0
for i in range(a):
    x,y=map(int,input().split())
    if(x<y):
        ans+=1
print(ans)