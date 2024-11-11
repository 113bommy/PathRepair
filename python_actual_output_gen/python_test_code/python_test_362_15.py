n=int(input())
k=int(input())
x=list(map(int,input().split()))
ans=0
for i in x:
    ans+=min(abs(x-k),abs(x))*2
print(ans)