n = int(input())
a = [list(map(int,input().split())) for i in range(2)]
ans = 0
for i in range(n):
  ans = max(ans , sum(a[0][0:i]) + sum(a[0][i:n-1]))
print(ans)