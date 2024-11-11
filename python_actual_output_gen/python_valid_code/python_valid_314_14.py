t = int(input())
for _ in range(t):
  n,s,k = map(int,input().split())
  a = sorted(list(map(int,input().split())))
  m = 0
  M = 0
  if(s not in a):
    print(0)
  else:
    for i in range(1,s):
      if(i not in a):
        m = abs(s-i)
        break
    for i in range(s+1,n+1):
      if(i not in a):
        M = abs(s-i)
        break
    if(m == 0):
      print(M)
    elif(M == 0):
      print(m)
    else:
      print(min(m,M))