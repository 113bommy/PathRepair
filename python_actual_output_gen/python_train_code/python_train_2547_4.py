N = int(input())
ans=0
for i in range(N):
    l,n= map(int, input().split())
    ans=l-n+1
print(ans)