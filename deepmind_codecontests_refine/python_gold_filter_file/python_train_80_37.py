N,M = map(int,input().split())
mod=10**9+7
A = {int(input()) for i in range(M)}

if 1 in A:
  x=0
else:
  x=1
B=[1,x]
for i in range(2,N+1):
  if i in A:
    B +=[0]
  else:
    B +=[(B[i-1]+B[i-2])%mod]
print(B[-1]%mod)