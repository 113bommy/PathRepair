N,M=map(int,input().split())
mod = 10**9+7
def fact_list(a):
  ans = [1]
  for i in range(1,a+1):
    ans.append(ans[-1]*i % mod)
  return ans

factlist = fact_list(M)

def comb_mod(a,b):
  return (factlist[a]*pow(factlist[b],mod-2,mod)*pow(factlist[a-b],mod-2,mod) )% mod

def permu_mod(a,b):
  return (factlist[a]*pow(factlist[a-b],mod-2,mod) % mod)

ans = 0
for i in range(N+1):
  ans += comb_mod(N,i)*(-1)**i*permu_mod(M,i)*permu_mod(M-i,N-i)**2 
  ans = ans % mod
print(ans)
