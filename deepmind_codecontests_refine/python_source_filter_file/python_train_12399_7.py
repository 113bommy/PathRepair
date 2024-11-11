#########################################################################################################\
#########################################################################################################
###################################The_Apurv_Rathore#####################################################
#########################################################################################################
#########################################################################################################
import sys,os,io
from sys import stdin
from math import log, gcd, ceil
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop
import math 
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r") ; sys.stdout = open("output.txt","w")
def ncr(n, r, p):  
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p
def primeFactors(n): 
    l = []
    while n % 2 == 0: 
        l.append(2)
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            l.append(int(i))
            n = n / i 
    if n > 2: 
        l.append(n)
    return list(set(l))
def power(x, y, p) : 
	res = 1
	x = x % p 
	if (x == 0) : 
		return 0
	while (y > 0) : 
		if ((y & 1) == 1) : 
			res = (res * x) % p 
		y = y >> 1	 # y = y/2 
		x = (x * x) % p 		
	return res 
def SieveOfEratosthenes(n):
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    return prime
def countdig(n):
    c = 0
    while (n > 0):
        n //= 10
        c += 1
    return c
def prefix_sum(arr):
    r = [0] * (len(arr)+1)
    for i, el in enumerate(arr):
        r[i+1] = r[i] + el
    return r
def divideCeil(n,x):
    if (n%x==0):
        return n//x
    return n//x+1
def si():
    return input()
def ii():
    return int(input())
def li():
    return list(map(int,input().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')




#__________________________TEMPLATE__________________OVER_______________________________________________________

# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
t = 1
# t = int(input())
for _ in range(t):
    n = ii()
    a = li()
    b = li()
    a.sort(reverse=True)
    b.sort(reverse=True)
    i = 0
    j = 0
    turn = 0
    A = 0
    B = 0
    while(i<n and j<n):
        if (turn==0):
            turn = 1
            if (a[i]>b[j]):
                A+=a[i]
                i+=1
            else:
                j+=1
        else:
            turn = 1
            if (a[i]>b[j]):
                i+=1
            else:
                B+=b[j]
                j+=1
            
    if (i<n):
        while(i<n):
            if(turn==0):
                A+=a[i]
                i+=1
                turn = 1
            else:
                turn = 1
                i+=1
    
    if (j<n):
        while(j<n):
            if(turn==0):
                B+=b[j]
                j+=1
                turn = 1
            else:
                turn = 1
                j+=1
    print(A-B)

