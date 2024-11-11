n = int(input())
h = tuple(map(int, input().split()))
ans = [0]*n
for i in range(1, n+1):
  ans[h[i]-1] = i+1
print(*ans)