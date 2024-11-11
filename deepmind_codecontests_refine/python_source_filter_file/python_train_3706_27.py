from math import *
def isPrimeNumber(n):
    if (n < 2):
        return False
    squareRoot = int(sqrt(n))
    for i in range(2, squareRoot + 1):
        if (n % i == 0):
            return False
    return True
a,b=map(int,input().split())
if isPrimeNumber(a)==True and isPrimeNumber(b)==True:
    t=0
    for i in range(a,b+1):
        if isPrimeNumber(i)==True:
            t=1
            break
    if t==0:
        print('YES')
    else:
        print('NO')
else:
    print('NO')


    
    


        











        