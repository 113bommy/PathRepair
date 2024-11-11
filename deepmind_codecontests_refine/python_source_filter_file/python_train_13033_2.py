import math
n,m = map(int , input().split())
l = []
def factorize(n): 
    count = 0; 
    
    while ((n % 2 > 0) == False):  
          
        n >>= 1;  
        count += 1; 
    
    if (count > 0): 
        l.append((2, count)) 
        
    for i in range(3, int(math.sqrt(n)) + 1): 
        count = 0; 
        while (n % i == 0):  
            count += 1; 
            n = int(n / i); 
        if (count > 0): 
            l.append((i, count)); 
        i += 2; 
        
    if (n > 2): 
        l.append((n, 1)); 
  
# Driver Code
factorize(n)
ans =1
v = 0
#print(l)
for i in range(len(l)):
    m1,j,v = m,1,0
    while(j<26):
        v+=m//pow(l[i][0],j)
        j+=1
    #print(v)
    ans = ans*pow(l[i][0],v,10**9+7)
    ans = ans%(10**9+7)
print(ans)
