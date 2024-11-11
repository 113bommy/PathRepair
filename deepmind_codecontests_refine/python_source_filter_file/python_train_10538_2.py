n, m, p = list(map(int, input().strip().split(" ")))
a = list(map(int, input().strip().split(" ")))
b = list(map(int, input().strip().split(" ")))
ans = -1
for i in range(n):
  if a[i] % p != 0:
    ans = i
    break
for i in range(n):
  if b[i] % p != 0:
    ans += i
    break
print(ans)