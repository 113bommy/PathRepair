N=int(input())
ans=0
for i in range(N):
    L,R=map(int,input().split())
    ans+=R-L+1
print(ans)