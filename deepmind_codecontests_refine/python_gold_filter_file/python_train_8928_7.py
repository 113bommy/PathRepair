h,w,k = map(int,input().split())
x1,y1,x2,y2 = map(int,input().split())
c = []
for i in range(h):
  c.append(list(input()))

q = [(1,x1-1,y1-1)]
c[x1-1][y1-1] = 0
while(q):
  qq = []
  for a,x,y in q:
    for dx,dy in ((0,-1),(0,1),(-1,0),(1,0)):
      for kk in range(1,k+1):
        xx = x+dx*kk
        yy = y+dy*kk
        if not (0 <= xx < h) or not (0 <= yy < w) or c[xx][yy] == '@' or (c[xx][yy] != '.' and c[xx][yy] < a):
          break
        if c[xx][yy] == '.' or (c[xx][yy] != '.' and c[xx][yy] > a):
          c[xx][yy] = a
          qq.append((a+1,xx,yy))
  #print(qq)
  q = qq[:]

print(-1 if c[x2-1][y2-1] == '.' else c[x2-1][y2-1])
#print(c)
