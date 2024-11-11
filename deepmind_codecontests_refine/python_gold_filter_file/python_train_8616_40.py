K = int(input())
S = input()
X = len(S)
mod = 10**9+7

temp = pow(26,K,mod)
ans = pow(26,K,mod)

Y = 25*pow(26, mod-2, mod)

for i in range(X+1,K+X+1):
   
    temp *= Y
    temp %= mod
    
    temp *= i-1
    temp %= mod
    
    temp *= pow(i-X, mod-2, mod)
    temp %= mod    

    ans += temp
    ans %= mod

print(ans)