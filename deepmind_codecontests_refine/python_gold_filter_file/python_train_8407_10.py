N,Q=map(int,input().split())
alist=list(map(int,input().split()))

#A1～Aiまでの和 O(logN)
def BIT_query(idx):
  res_sum = 0
  while idx > 0:
    res_sum += BIT[idx]
    idx -= idx&(-idx)
  return res_sum
#Ai += x O(logN)
def BIT_update(idx,x):
  while idx <= N:
    BIT[idx] += x
    idx += idx&(-idx)
  return

BIT=[0]*(N+1)
for i in range(N):
  BIT_update(i+1,alist[i])

for _ in range(Q):
  q1,q2,q3=map(int,input().split())
  if q1==0:
    BIT_update(q2+1,q3)
  else:
    print(BIT_query(q3)-BIT_query(q2))