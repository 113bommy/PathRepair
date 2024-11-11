n, k, d = map(int, input().split())
M = 1000000007
a = [1] + [0] * n
for i in range(1, n + 1):
  for j in range(max(0, i - k), i):
    a[i] = (a[i] + a[j]) % M
# print(a)
b = [1] + [0] * n
for i in range(1, n + 1):
  for j in range(max(0, i - d + 1), i):
    b[i] = (b[i] + b[j]) % M
# print(b)
print(abs(a[n] - b[n]))