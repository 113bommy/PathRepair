import math
def isPrime(n):
    l = 0
    for i in range(2,int(math.sqrt(n))+1):
        if(n%i==0):
            l+=1
            break
    if(l==0):
        return True
    else:
        return False
def lowest_divisor(n):
    for i in range(2,int(math.sqrt(n))+1):
        if(n%i==0):
            return i
n = int(input())
a = [0]*(n-1)
p = 2
for i in range(len(a)):
    if(i%2==0):
        a[i] = 1
    else:
        if(isPrime(i)):
            a[i] = p
            p+=1
        else:
            k = lowest_divisor(i)
            a[i] = a[k-2]
print(*a)
