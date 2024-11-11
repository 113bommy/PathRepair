from math import factorial as fact
 
def v(n,k):
    return fact(n)/fact(n-k)
def c(n,k):
    return int(fact(n)/(fact(n-k)*fact(k)))
 
n = int(input())
print(c(n,5)*c(n,6)*c(n,7))