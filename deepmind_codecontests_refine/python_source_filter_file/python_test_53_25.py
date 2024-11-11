#######################################################################################################
#######        ###########         #######    #########    #######           ######               #####
######  ######  #########  ######  #######  ###########  #############   ################  ############
######  #######  ########  #######  ######  ###########  ##############  ################  ############
######  ######  #########  #######  ######               #############   ################  ############
######  ###   ###########  #######  ######  ###########  #############   ################  ############
######  #####  ##########  #######  ######  ###########  #############   ################  ############
######  ######  ##########  #####  #######  ###########  #############   ################  ############
####     ######     ######        ######    ########      #######            ##########     ###########
#######################################################################################################
import sys
#-----------------------IMPORTANT  FUNCTIONS ---------------------------------#
from math import cos, pi, ceil, pi, tan, floor, gcd, sqrt, log2, factorial, log10
from collections import Counter
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase
from statistics import mean, median, mode
from bisect import *

alpha = ascii_lowercase
beta = ascii_uppercase


#-----------------------NEXT POWER OF 2---------------------------------------#
def nextPowerOf2(n):
    p = 1
    if (n and not (n & (n - 1))):
        return n
    while (p < n):
        p <<= 1
    return p


#-----------------------GET DIVISORS 1 TO <=N   ------------------------------#
def get_Divisors(n):
    arr = []
    i = 1
    while i <= sqrt(n):
        if (n % i == 0):
            if (n / i == i):
                arr.append(i)
            else:
                arr.append(i)
                arr.append(n // i)
        i = i + 1

    return arr


#----------------------CHECK    PRIMES-----------------------------------#
def isprime(n):
    if n == 1:
        return 0
    i = 2
    while (i * i <= n):
        if (n % i == 0):
            return 0
        i += 1
    return 1


#-----------------------PRE COMPUTED  PRIMES-----------------------------------#
def Sieve(n):
    prime = [True for i in range(n + 1)]
    prime[0] = False
    prime[1] = False
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
    return prime


#-----------------------LARGER VALUE OF  X,Y,10**9+7 --------------------------#
def power(x, y, p):
    res = 1
    x = x % p
    if (x == 0):
        return 0
    while (y > 0):
        if ((y & 1) == 1):
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res


#-----------------------       CREATE MATRIX         --------------------------#
def create_matrix(n, m):
    mat = [[] for i in range(n)]
    for i in range(n):
        for j in range(m):
            mat[i].append(0)
    return mat


#By Default Counter stores the value in decending orderCounter({4: 2, 8: 2, 2: 1, 9: 1}
#s=sorted(s.items(),key=lambda k:(k[0],k[1])) ---> [(2, 1), (4, 2), (8, 2), (9, 1)]
#sort 2nd value  from bada se chhota  then(4,2)(8,2)->>(8,2)(4,2) s=sorted(s.items(),key=lambda k:(-k[1],-k[0]))  [(8, 2), (4, 2), (9, 1), (2, 1)]
#for list pair in a list    s.sort(key=lambda k:(-k[1],-k[0])) [[3, 4], [8, 2], [4, 2]]
# from functools import cmp_to_key
# def compare(x, y):
#     if x + y > y + x:
#         return -1
#     elif x + y < y + x:
#         return 1
#     else:
#         return 0
#how to use compare ----ss = sorted(s, key=cmp_to_key(compare))
# a=[1,4,5,9,12,15]
# print(bisect(a,9))
# insort(a,9)
# print(a)
#arr=[-14,-10,2,108,108,243,285,285,401]
# print(bisect_left(arr,-10))
# print(bisect_left(arr,108))
# print(bisect_left(arr,501))
# print(bisect_left(arr,200))
# print(bisect_left(arr,-20))
#**************************************
# print(bisect_right(arr,-10))
# print(bisect_right(arr,108))
# print(bisect_right(arr,501))
# print(bisect_right(arr,200))
# print(bisect_right(arr,-20))
#-----------------------*****CODE STARTS  HERE*****--------------------------#

# from queue import Queue
# from random import *
def main():
    for ttt in range(int(input())):
        n,k=map(str,input().split())
        s=input()
        n=int(n)
        if s==k*n:
            print(0)
            continue 
        ok=0 
        ind=-1 
        for i in range(n):
            if s[i]==k:
                ok=1 
                ind=i 
        if ok==0:
            print(2)
            print(n-1,n)
        elif ind==n-1:
            print(1)
            print(n)
        elif ind>n//2:
            print(1)
            print(ind+1)
        else:
            print(2)
            print(n-1,n)
            
            
            
        
            
        
        
                
        
if __name__ == "__main__":
    main()

