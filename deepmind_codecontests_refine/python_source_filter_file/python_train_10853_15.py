import io,os
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
import sys
from math import ceil,sqrt

def prime_judge(n):
    if n==2:
        return True
    if n<2 or n%2==0:
        return False
    for i in range(3,int(ceil(sqrt(n)))+1,2):
        if n%i==0:
            return False
    return True

def solve(n):
    if n==1:
        return 'FastestFinger'
    if n==2:
        return 'Ashishgup'
    if n%2==1:
        return 'Ashishgup'
    m=n
    while n%2==0:
        n//=2
    if n==1:
        return 'FastestFinger'
    r=m//n
    if r!=2:
        return 'Ashishgup'
    if prime_judge(r):
        return 'FastestFinger'
    return 'Ashishgup'

def main():
    t=int(input())
    for _ in range(t):
        n=int(input())
        ans=solve(n)
        sys.stdout.write(str(ans)+'\n')
    
if __name__=='__main__':
    main()