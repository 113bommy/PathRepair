from math import sqrt
n = int(input())

def isPrime(a):
    if(a<2):
        return False
    for i in range(2,int(sqrt(a))):
        if (a%i==0):
            return False
    return True

t = [int(x) for x in input().split()]
 
for i in range(n):
    k = sqrt(t[i])
    if k == int(k):
        answer = isPrime(int(k))
        if answer == True:
            print('YES')
        else:
            print('NO')
    else:
        print('NO')