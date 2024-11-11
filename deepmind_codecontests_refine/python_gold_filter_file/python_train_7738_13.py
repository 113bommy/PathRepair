def Prime(n):
    if 2>n:
        return False
    if 2==n:
        return True
    if n%2==0:
        return False
    for i in range(3,int(n**0.5)+1,2):
        if n%i==0:
            return False
    return True
 
 
num,k = map(int,input().split())
primes = [i for i in range(num+1) if Prime(i)]
count = 0
 
for i in range(len(primes)):
    p = primes[i]
    for j in range(i-1):
        if primes[j]+primes[j+1]+1==p:
            count+=1
            break
    if count>=k:
        break
 
if count>=k:
    print("YES")
else:
    print("NO")