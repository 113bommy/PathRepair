n, k = map(int, input().split())

ans = pow(n // k, 3)
if k % 2 == 0:
  ans += pow((n + k // 2) // k, 3)
print(ans)