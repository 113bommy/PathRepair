def isPrime(n):
    flag=0
    for i in range(2,n//2+1):
        if n%i==0:
            flag=1
            break
    return([1,0][flag==0])
n=int(input())
for i in range(4,n//2):
    if isPrime(i) and isPrime(n-i):
        print(i, n - i)
        break