mod = 10**9+7
fact = [1]
fact_inv = [1]
for i in range(10**5):
  new_fact = fact[-1]*(i+1)%mod
  fact.append(new_fact)
  fact_inv.append(pow(new_fact,mod-2,mod))

def mod_comb_k(n,k,mod):
  return fact[n]*fact_inv[k]%mod*fact_inv[n-k]%mod

N,K = map(int,input().split())
arr = list(map(int,input().split()))
arr = sorted(arr)
_max = 0
_min = 0
for i in range(K-1,N):
  _max += arr[i]*mod_comb_k(i,K-1,mod)
  _min += arr[i-K+1]*mod_comb_k(N-i+K-2,K-1,mod)
print(_max-_min)