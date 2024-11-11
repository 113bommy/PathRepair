N=int(input())
A=map(int,input().split())
A.sort()
r=A[0]
for i in range(1,N,1):
  r=float((r+A[i])/2)
print(r)