H, W = map(int, input().split())


HW=[ [-1 for w in range(W)] for h in range(H) ]

#print(HW)
from collections import deque
Q = deque()

for h in range(H):
  S = input()
  for w in range(W):
    if S[w]=="#":
      Q.append([h,w])
      HW[h][w]=0

X = [0,0,-1,1]
Y = [-1,1,0,0]
ans=0

while Q:
  h,w = Q.popleft()

  for i in range(len(X)):
    ih,iw = h + Y[i], w + X[i]

    if not ((0 <= ih < H) and (0 <= iw < W)): continue
    if HW[ih][iw] >= 0: continue

    HW[ih][iw] = HW[h][w]+1
    ans = max(ans, HW[ih][iw])
    Q.append([ih,iw])

print(ans)






