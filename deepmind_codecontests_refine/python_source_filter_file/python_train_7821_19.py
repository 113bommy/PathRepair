n = int(input())
a = list(map(int, input().split()))

res = 0
max_now = 10**9
for i in range(n - 1, -1, -1):
  if a[i] < max_now:
    res += a[i]
    max_now = a[i]
  else:
    max_now -= 1
    res += max_now
  if max_now == 0:
    break
print(res) 