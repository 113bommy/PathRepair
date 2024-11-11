def rem(x,r):
  if (x,r) == (1,0):
    return [[1]]
  if x <= 2*r:
    return -1
  ret = []
  for i in range(1,x+1):
    if x%i == r:
      ret.append([i])
    else:
      s = rem(x%i,r)
      if s == -1:
        continue
      else:
        for j in s:
          if j == -1:
            continue
          elif j[-1] < i:
            ret.append([i]+j)
          else:
            ret.append([i]+j)
  return ret
n = int(input())
x = list(map(int,input().split()))
y = list(map(int,input().split()))
for xx,yy in zip(x,y):
  if xx != yy and rem(xx,yy) == -1:
    print(-1)
    exit()
ls = [rem(xx,yy) if xx != yy else 0 for xx,yy in zip(x,y)]
flg = [0]*n
def findmx(lsi,ansst,mx):
  ret = 100
  if lsi == 0:
    return 0
  for lsls in lsi:
    for j in lsls:
      if j > mx:
        return min(j,ret)
      elif j in ansst:
        continue
      else:
        ret = min(j,ret)
        break
    else:
      return 0
  else:
    return ret
    
mxls = [ls[i][0][0] if type(ls[i]) == list else 0 for i in range(n)]
mx = max(mxls)
ansst = set((mx,))
mxcand = mx
while mxcand:
  for i in range(n):
    t = findmx(ls[i],ansst,mx)
    mxls[i] = t
    if t == 0:
      flg[i] = 1
  mxcand = max(mxls)
  ansst.add(mxcand)
  if flg.count(1) == n:
    break
ans = 0
for b in ansst:
  if b:
    ans += 2**b
print(ans)