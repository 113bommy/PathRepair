n=int(input())
A=list(map(int,input().split()))
Q=[]
for i in range(1,n):
  Q.append(sum(A[:i])-sum(A[i:]))
print(min(Q))