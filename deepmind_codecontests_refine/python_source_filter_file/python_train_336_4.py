n=int(input())
def modFact(n, p): 
    if n >= p: 
        return 0    
  
    result = 1
    for i in range(1, n + 1): 
        result = (result * i) % p  
  
    return result 
p = 10**9 + 7
print(modFact(n,p)-pow(2,n-1,p))