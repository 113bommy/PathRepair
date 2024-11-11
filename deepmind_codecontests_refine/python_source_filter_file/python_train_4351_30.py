l = []

for _ in range(3):
  l += list(map(int, input().split()))

n = int(input())
for _ in range(n):
  b = int(input())
  if b in l:
    l[l.index(b)] = 0

for i in range(3):
  if sum(l[0+3*i:3+3*i]) == 0:
    print("Yes")
    exit()
  
  if sum(l[i:8:3]) == 0:
    print("Yes")
    exit()

if (l[0]+l[4]+l[8]) == 0:
  print("Yes")
  exit()
if (l[2]+l[4]+l[6]) == 0:
  print("Yes")
  exit()
  
print("No")
