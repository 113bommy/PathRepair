n=int(input())
h=[0]+list(map(int, input().split()))
ans=0

for i in range(n):
    ans+=max(h[i+1]-h[i],0)

print(ans)