import sys
input = sys.stdin.readline
def inputs():return [int(x) for x in input().split()]
N,K = inputs()
xy = [inputs() for _ in range(N)]
#xy = sorted(xy,key=lambda x: x[1])
xy = sorted(xy,key=lambda x: x[0])
#print(xy)
ans = 10**20
for i in range(N-K+1):
  for j in range(i+K-1,N):
    #print(i,j)
    xy1 = xy[i:j+1]
    #print(xy1)
    xy1 = sorted(xy1,key=lambda x: x[1])
    mi = min(xy1[i+K-1]-xy1[i] for i in range(len(xy1)-K+1))
    ans = min(ans,(xy[j][0]-xy[i][0])*mi)
print(ans)
    
    