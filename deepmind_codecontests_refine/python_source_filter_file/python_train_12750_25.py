from math import*
def F(x):
    res=1
    for c in x:
        res=res*factorial(int(c))
    return res
def coef(x,n):
    res=0
    while n%(x**(res+1))==0:
        res=res+1
    return res

n=int(input())
x=str(input())
L=list()
n=F(x)

while (n%factorial(7))==0:
    L.append("7")
    n=n/(factorial(7))
while (n%factorial(5))==0:
    L.append("5")
    n=n/(factorial(5))
while (n%factorial(3))==0:
    L.append("3")
    n=n/(factorial(3))
while (n%factorial(2))==0:
    L.append("2")
    n=n/(factorial(2))

    
    
L.sort()
L=L[::-1]
print("".join(L))