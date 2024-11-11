from math import sqrt 

n = int(input())

def isPrime(num):
    if num==2 or num==3: return True
    #even number except 2 cannot be prime
    if num%2==0 or num<2: return False
    #only odd numbers
    for i in range(3, int(sqrt(num))+1, 2):
        if num%i==0:
            return False
    
    return True
    
  
if n%2!=0:
    print(1)
else:
    m = 1
    while m<=1000:
        
        if not isPrime(n*m+1):
            print(m)
            break
        
        m+=1
        
        
        
    
    


