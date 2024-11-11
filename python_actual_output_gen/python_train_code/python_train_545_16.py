n=int(input())
A=list(map(int,input().split()))[::-1]
B=[0]*n
for i in range(n):
  k=n-i
  if A[i]!=(B[k-1::k].count(1))%2:
    B[k-1]=1
    
o=B.count(1)
print(o)
P=[[i for i, x in enumerate(B) if x ==1]]
if o!=0:
  print(*P[0])
