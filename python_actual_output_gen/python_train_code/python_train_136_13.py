n = int(input())
a = [int(input()) for i in range(n)]
q = set(sorted(a))

for i in range(n):
  if a[i] != q[-1]:
    print(q[-1])
  else:
    print(q[-2])