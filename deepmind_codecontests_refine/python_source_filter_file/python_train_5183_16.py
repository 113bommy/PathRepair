from collections import defaultdict
N,*A = map(int, open(0).read().split())
dp_not = defaultdict(lambda :-10**10)
dp_take = defaultdict(lambda :-10**10)
dp_not[(0,0)] = 0
for i,x in enumerate(A,1):
  for j in ((i-1)//2,(i-1)//2+1):
    dp_not[(i,j)] = max(dp_not[(i-1,j)],dp_take[(i-1,j)])
    dp_take[(i,j)] = dp_not[(i-1,j-1)] + x
print(max(dp_not[(N,N//2)], dp_take[(N,N//2)]))