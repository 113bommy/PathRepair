n = int(input)
s=0
for i in range(n):
  s,e = map(int,input().split())
  s += e-s+1
print(s)