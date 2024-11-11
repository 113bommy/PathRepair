N,M=map(int,input().split())
x=[int(i) for i in input().split()]
y=[int(i) for i in input().split()]
P=10**9+7
X=0
Y=0
for i in range(1,N+1):
  X+=x[i-1]*(2*i-1-N)
  X=X%P
for j in range(1,M+1):
  Y+=y[j-1]*(2*j-1-M)
  Y=Y%P
print((X*Y)%P)
