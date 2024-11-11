c=0
N=int(input())
for i in range(N):
  *A=map(int, input().split())
  c+=A[1]-A[0]+1
print(c)