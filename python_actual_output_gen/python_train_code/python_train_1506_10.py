n = int(input())
a = []
for i in range(n):
  s, p = input().split()
  a.append([s,-int(p),i])
a.sort()
for i in a:
  print(i[-1])
