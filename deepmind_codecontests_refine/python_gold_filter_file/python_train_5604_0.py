def isPrime(n):    
    for i in range(2,int(n**(1/2))+2):
        if n%i==0:
            return False
    return True

N=int(input())

l=[]

for i in range(2,55556):
    if len(l)>=N:
        break
    if isPrime(i) and i%5==1:
        l.append(i)

print(*l)