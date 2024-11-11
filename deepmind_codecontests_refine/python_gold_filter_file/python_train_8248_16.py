import math

for t in range(int(input())):
  n = int(input())
  #a,b = (int(i) for i in input().split())
  #a = list(input())
  a = [int(i) for i in input().split()]
  a.sort()
  aset = set(a)
  if n%2==1:
    print(-1)
  elif n == 2 and a[1]!=a[0]:
    print(a[1]^a[0])
  elif n==2:
    print(-1)
  else:
    ds = set()
    rems = set()
    for i in range(n):
      ds.add(a[i]^a[0])
    ds.remove(0)
    if len(ds)==0:
      print(-1)
      continue
    for i in sorted(list(ds)):
      naset = []
      done = False
      for j in a:
        naset.append(j^i)
      #print(naset)
      if sorted(naset) == a:
        done = i
        break
    if done:
      print(done)
    else:
      print(-1)

