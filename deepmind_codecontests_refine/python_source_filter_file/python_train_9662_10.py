n=int(input())
h=list(map(int, input().split()))
ans=0

for i in range(n-1):
    ans+=max(h[i+1]-h[i], 0)

print(ans)