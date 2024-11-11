a, b = map(int, input().split())
n = 0
for i in range(a, b + 1):
  if str(i) == str(i)[::-1]:
    n += 1
print(n)
