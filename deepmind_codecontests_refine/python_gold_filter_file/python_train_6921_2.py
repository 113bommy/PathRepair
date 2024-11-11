n = int(input())
a = list(map(int, input().split()))
a.sort()
t = a[0]
ans = 1
for i in range(1, n):
  if a[i] >= t:
    ans += 1
    t += a[i]
print(ans)