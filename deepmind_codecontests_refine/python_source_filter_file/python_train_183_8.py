N=int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
t=0
k=0
for i in A:
  t+=B[i-1]
  if k+1==i:
    t+=C[k-1]
  k=i
print(t)