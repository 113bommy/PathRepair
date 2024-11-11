import math
n=int(input())
def isPrime(n):
    if n is 1: return False
    i=2
    while i<math.sqrt(n):
        if n%i == 0:
            return False
        i+=1
    return True
for i in range(n):
    a,b=map(int,input().split())
    if a-b > 1:
        print('NO')
        continue
    print('YES') if isPrime(a+b) else print("NO")
