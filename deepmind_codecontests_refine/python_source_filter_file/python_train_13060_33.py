import math

n = int(input())

def primenumber(pom):
    for j in range(2,int(math.sqrt(pom))+1):
        if pom%i==0:
            return True
    return False
for i in range(4,n,2):
    pom = n-i
    if primenumber(pom):
        print(pom,i)
        break
        
   
        
        
