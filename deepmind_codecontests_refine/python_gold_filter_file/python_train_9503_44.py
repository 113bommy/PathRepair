n = int(input())

def factorial(n):
    fact =1
    if(n ==0 or n==1):
    
        return n
    else:
        for i in range(1,n+1):
        
            fact = fact*i;
        
        return fact
    
r = n/2
result = factorial(n-1)/r
print(int(result))
