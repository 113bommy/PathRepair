n = int(input())
a = list(map(int, input().split(' ')))

b = sorted(a)
b.reverse()

d = {}

c = [0]*(n)

for i in range(n):
  if b[i] not in d:
    d[b[i]] = i
  

for i in range(n): 
  c[i] = d[a[i]]+1

print(c)
  