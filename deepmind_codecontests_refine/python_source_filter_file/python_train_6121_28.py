N = int(input())

A = list(map(int, input().split()))

ans = [0]*N
for i in range(N):
    ans[i-1]=i+1
print(*ans)