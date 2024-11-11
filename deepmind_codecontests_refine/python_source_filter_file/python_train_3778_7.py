'''Author- Akshit Monga'''
from sys import stdin,stdout
input=stdin.readline
import math

def printDivisors(n,q):
    i = 1
    ans=-1
    while i <= math.sqrt(q):
        if (n % i == 0):
            if n/i==i and i%q!=0:
                ans=max(ans,i)
            else:
                if i%q!=0:
                    ans=max(ans,i)
                if (n//i)%q!=0:
                    ans=max(ans,(n//i))
        i = i + 1
    print(ans)


def primeFactors(n):
    arr=set()
    while n % 2 == 0:
        arr.add(2)
        n = n / 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            arr.add(i)
            n = n / i
    if n > 2:
        arr.add(n)
    return arr

t = int(input())
for _ in range(t):
    p,q=map(int,input().split())
    if p<q:
        print(p)
    elif p==q:
        printDivisors(p,p)
    else:
        if p%q!=0:
            print(p)
        else:
            q1=q
            q2=p//q
            arr=list(primeFactors(q1))
            ans=-1
            for i in arr:
                val1=q1//i
                val2=q2
                while val2 % i == 0:
                    val2=val2/ i
                ans=max(ans,val1*val2)
            ans=int(ans)
            stdout.write(str(ans)+'\n')
            # print(int(ans))