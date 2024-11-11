MOD = 10**9+7
n,k = map(int,input().split())

L = [0]*(k+1)

for i in range(k,0,-1):    
  L[i] = pow(k//i,n,mod)
  for j in range(2,k//i+1):        
    L[i] -= L[i*j]
  
ans = 0
for i in range(1,k+1):  
  ans = (ans + i*L[i]) % MOD
  
print(ans)  