a=[]
b=[]
m=0

for _ in [0]*int(input()):
  a += input()
for _ in [0]*int(input()):
  b += input()

for s in a:
  m = max(m, a.count(s)-b.count(s))
print(m)
