import sys
input = sys.stdin.readline
import itertools
n,k=map(int,input().split())
X,Y,XY=[0]*n,[0]*n,[0]*n
for i in range(n):
  x,y=map(int,input().split())
  X[i],Y[i],XY[i]=x,y,[x,y]
X.sort()
Y.sort()
def count(x1,x2,y1,y2):
  ct=0
  for x,y in XY:
    if x1<=x<=x2 and y1<=y<=y2:
      ct+=1
  return ct
ans=float("inf")
for x1,x2 in itertools.combinations(X,2):
  for y1,y2 in itertools.combinations(Y,2):
    if count(x1,x2,y1,y2)==k:
      ans=min(ans,abs((x1-x2)*(y1-y2)))
print(ans)