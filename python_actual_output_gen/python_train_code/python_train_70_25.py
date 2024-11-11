N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))
s=0
for i in range(N):
  s+=B[A[i]-1]
  if i!=0 and A[i-1]+1==A[i]:
    s+=C[i]
print(s)