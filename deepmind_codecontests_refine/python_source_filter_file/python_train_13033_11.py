import math 

def primeFactors(n): 
    prime = list()
    while n % 2 == 0: 
        prime.append(2) 
        n = n // 2
   
    for i in range(3,int(math.sqrt(n))+1,2): 
       
        while n % i== 0: 
            prime.append(i)
            n = n // i 
   
    if n > 2: 
        prime.append(n)
    return prime
          
x, n = map(int, input().split())
d = primeFactors(x) 
if(len(d) == 0):
    d.append(x)
ans = 1
for ele in d:
    #print(ele)
    temp, pw = ele, 0
    while n//temp > 0:
        pw += (n//temp)
        temp = temp*ele
    ans = (ans*pow(ele, pw, 10**9 + 7))%(10**9 + 7)
print(ans)
        
    
    
