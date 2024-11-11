from collections import deque
printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7
#R = 998244353

def ddprint(x):
  if DBG:
    print(x)

h,w,k = inm()
a = []
for i in range(h):
    t = ins()
    a.append(t)
    v = t.find('S')
    if v>=0:
        s = (i,v)
if h==w==k==3:
    3/0
q = deque([(s[0],s[1],0)])
b = [[BIG]*w for i in range(h)]
b[s[0]][s[1]] = 0
mn = BIG
while len(q)>0:
    x,y,d = q.popleft()
    mn = min([ \
      mn,(x+k-1)//k,(h-1-x+k-1)//k,(y+k-1)//k,(w-1-y+k-1)//k])
    if d>=k:
        continue
    for dx,dy in [(0,1),(0,-1),(1,0),(-1,0)]:
        xx = x+dx
        yy = y+dy
        if 0<=xx<h and 0<=yy<w and a[xx][yy]!='#' and \
           b[xx][yy]==BIG:
            b[xx][yy] = d+1
            q.append((xx,yy,d+1))
print(mn+1)
