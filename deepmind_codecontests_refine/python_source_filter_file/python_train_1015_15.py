n,k = map(int,input().split())
scale = 21
#scale = 4
seg = [0 for _ in range(2**scale)]
db = [2**i for i in range(scale)]
rdb = list(reversed(db))
#print(rdb)
for _ in range(n):
  c = int(input())
  l = max(c-k,0)
  r = min(c+k+1,2**(scale-1))
  maxi = 0
  now = [[l,r]]
  #print(now)
  for i in range(scale):
    last = now
    now = []
    for xy in last:
      x,y = xy
      if x == y:
        continue
      X = (x-1) // rdb[i] + 1
      Y = y     // rdb[i]
      #print(x,y,X,Y,rdb[i])
      if X < Y:
        for Z in range(X,Y):
          maxi = max(maxi,seg[db[i]+X])
          now.append([x,X*rdb[i]])
          now.append([Y*rdb[i],y])
      else:
        now.append(xy)
      #print(int(X<Y),X,maxi)
    #print(now,rdb[i],maxi)
  c += db[-1]
  while True:
    seg[c] = max(seg[c],maxi + 1)
    c //= 2
    if not c:
      break
  #print(seg)
print(seg[1])