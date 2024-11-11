from math import gcd


n = int(input())

l = list(map(int,input().split()))

z = max(l)
g = 0
count = 0
for i in l:
    if i!=z:
        g = gcd(g,i)
    count+=z-i
if len(set(l)) == 1:
    print(0,0)
    exit()


if n == 2:
  if count != 0:
    print(1,count)
  else:
      print(0,count)
  exit()
print(count//g,g)
