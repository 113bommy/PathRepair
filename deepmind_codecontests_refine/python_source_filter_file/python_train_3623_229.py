n,k = map(int, input().split())

ans = n-k+1

if k == 1:
  ans = 0
print(ans)