fact=[1];pow_2=[1]
MOD=1000000007
for i in range(1,1000001):
    fact.append((fact[-1]*i)%MOD)
    pow_2.append((pow_2[-1]*2)%MOD)
for _ in range(1):
    n=int(input())
    print(fact[n]-pow_2[n-1])
    
