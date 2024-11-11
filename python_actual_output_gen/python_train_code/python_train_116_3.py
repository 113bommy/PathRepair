def modFact(n, p): 
    if n >= p: 
        return 0    
  
    result = 1
    for i in range(1, n + 1): 
        result = (result * i) % p  
  
    return result 
  
def maxWays(n,p): 
      
    # return (2^(n - 1)) -2  
    return ((pow(2, n - 1) - 2)%p); 
   

# Driver Code 
n = int(input())
p = 10**9+7
a=modFact(n, p)
print(a-maxWays(n,p)-2)