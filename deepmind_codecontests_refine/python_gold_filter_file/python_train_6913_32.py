import sys
import math
from sys import stdin, stdout
 
# Most Frequently Used Number Theory Concepts
# SOE(helper function of get gcd)
def sieve(N):
    primeNumbers = [True]*(N+1)
    primeNumbers[0] = False
    primeNumbers[1] = False
    i = 2
    while i*i <= N:
        j = i
        if primeNumbers[j]:
            while j*i <= N:
                primeNumbers[j*i] = False
                j += 1
        i += 1
    return primeNumbers
 
# get prime number form 1 to N
def getPrime(N):
    primes = sieve(N)
    result = []
    for i in range(len(primes)):
        if primes[i]:
            result.append(i)
    return result
 
# factors of n
def factor(N):
    factors = []
    i = 1
    while i*i <= N:
        if N % i == 0:
            factors.append(i)
            if i != N//i:
                factors.append(N//i)
        i += 1
    return sorted(factors)
 
# reduce a string in number under range(1000000007)
def reduceB(b) : 
    # Initialize result 
    mod = 0
    # Calculating mod of b with a 
    # to make b like 0 <= b < a 
    for i in range(0, len(b)) : 
        mod = (mod * 10 + ord(b[i])) % 1000000007 
        # print(b[i], ord(b[i]), mod)
    return mod	 # return modulo 
 
# gcd of two numbers
def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if b == 0:
        return a
    return gcd(b, a % b)
 
# TAKE INPUT
def get_ints_in_variables():
    return map(int, sys.stdin.readline().strip().split())
def get_int(): return int(input())
def get_ints_in_list(): return list(
    map(int, sys.stdin.readline().strip().split()))
def get_list_of_list(n): return [list(
    map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
def get_string(): return sys.stdin.readline().strip()

def pow(num, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        return pow(num*num, int(p/2))
    elif p % 2 != 0:
        return num * pow(num*num, int(p/2))

def main():
    # Write Your Code Here
    k, d = get_ints_in_variables()
    if d == 0:
        if k == 1:
            print(0)
            return
        else:
            print("No solution")
            return
    else:
        res = d*pow(10, k-1)
        print(res)
    
    
# for printing format
# print("Case #{}: {}".format(t+1, ans))
#  calling main Function
if __name__ == "__main__":
    main()