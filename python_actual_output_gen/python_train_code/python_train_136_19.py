n = int(input())
a = [input() for i in range(n)]
b = sorted(a)
for j in range(n):
  if a[j] == b[-1]:
    print(b[-2])
  else:
    print(b[-1])