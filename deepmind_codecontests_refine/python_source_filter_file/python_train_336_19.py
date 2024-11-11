n = int(input()) 
p = int(1e9+7) 
fact = [1]*(n+1) 

for i in range (1, n+1): 
    fact[i] = (i*fact[i-1])%p 

print (fact[n] - pow(2, n-1, p)) 