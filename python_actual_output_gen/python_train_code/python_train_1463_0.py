n, m = int(input()), int(input())
a = []
for _ in range(n):
  a.append(int(input()))
a.sort(reverse=True)
i = 0
cnt = 0
while cnt < m:
  cnt += a[i]
  i += 1
print(i + 1)