n = int(input())
l = []
for i in range(n):
  l.append(list(map(int,input().split())))
m = []
for i in l:
  a,b = i
  k.append(a+b)
  m.append(a-b)
k.sort()
m.sort()
print(max([k[-1]-k[0],m[-1] -m[0]]))