n,k = map(int,input().split())
p = [0] + list(map(int,input().split()))
c = [0] + list(map(int,input().split()))
maxsc = -1E20
for s in range(1,n+1):
  x = s
  sc = [0]
  i = 0
  while i<k:
    x = p[x]
    sc.append(sc[i]+c[x])
    i += 1
    if x == s:
      loop = i
      loopsc = sc[i]
      if loopsc > 0:
        baseup = loopsc * int((k-i)/loop)
        for j in range(loop):
          sc[j+1] += baseup
        for j in range((k-i)%loop):
          sc[j+1] += loopsc
      i=k
  sc[0] = -1e20
  maxsc = max(maxsc, max(sc))
print(maxsc)
    
