#	✪ H4WK3yE乡
#	Mayank Chaudhary
#	ABES EC , Ghaziabad
# ///==========Libraries, Constants and Functions=============///
import sys
from bisect import bisect_left,bisect_right
from collections import deque,Counter
from math import gcd,sqrt,factorial,ceil,log
from itertools import permutations
inf = float("inf")
mod = 1000000007
mini=1000000007

def fact(n):                                                             # <------  To calculate factorial of n under modulo m
    if n==0:
        return 1
    p=1;d=(10**9)+7
    for i in range(1,n+1):
        p=p*i
        p=p%d
    return p
def ncr(n,r):                                                          # < ------ To calculate nCr mod p value using Fermat Little under modulo m
    d=10**9+7
    num=fact(n)
    den=(fact(r)*fact(n-r))%d
    den=pow(den,d-2,d)
    return (num*den)%d
def sieve(n):                                                          # <----- sieve of eratosthenes for prime no.
    prime=[True for i in range(n+1)]
    lst=[]
    p=2
    while p*p<=n:
        if prime[p]:
            for i in range(p*p,n+1,p):
                prime[i]=False
        p=p+1
    for i in range(2,n+1):
        if prime[i]:
            lst.append(i)
    return lst
        
def binary(number):                                             #  <----- calculate the no. of 1's in binary representation of number
    result=0
    while number:
        result=result+1
        number=number&(number-1)
    return result

def calculate_factors(n):                                #<---- most efficient method to calculate no. of factors of number             
    hh = [1] * (n + 1); 
    p = 2; 
    while((p * p) < n): 
        if (hh[p] == 1): 
            for i in range((p * 2), n, p): 
                hh[i] = 0; 
        p += 1;  
    total = 1; 
    for p in range(2, n + 1): 
        if (hh[p] == 1):  
            count = 0; 
            if (n % p == 0): 
                while (n % p == 0): 
                    n = int(n / p); 
                    count += 1; 
                total *= (count + 1); 
    return total;

def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()
# ///==========MAIN=============///
k=int(input())
l=int(input())
store=round(log(l)/log(k))
if pow(k,store)==l:
    print("YES")
    print(store-1)
else:
    print("NO")
