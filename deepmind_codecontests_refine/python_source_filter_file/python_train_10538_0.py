
def main():
    
    n,m,p=readIntArr()
    a=readIntArr()
    b=readIntArr()
    
    # Since gcd(all a)==gcd(all b)==1 != p, at least 1 of a and b are not multiples of p.
    # Match the earliest a and b that are not multiples of p. The earlier a terms
    # and b terms are multiples of p, guaranteeing that aftering multiplying, they
    # still produce multiples of p. However, the 2 non-multiples will lead to
    # the sum not being a mulitple of p.
    t=0
    for i in range(n):
        if a[i]%p==0:
            t+=i
            break
    for i in range(m):
        if b[i]%p==0:
            t+=i
            break
    print(t)
    
    return
    
import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
# import sys
# input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.
 
def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([''.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
 
inf=float('inf')
MOD=10**9+7
 
for _ in range(1):
    main()