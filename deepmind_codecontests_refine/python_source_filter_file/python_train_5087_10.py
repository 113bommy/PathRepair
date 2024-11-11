n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(a):
  if a[a[i] - 1] == i + 1:
    ans += 1
print(ans // 2)