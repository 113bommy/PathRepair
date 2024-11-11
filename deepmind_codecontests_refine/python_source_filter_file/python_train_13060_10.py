# -*- coding: utf-8 -*-
"""
Created on Tue Jul 17 22:07:03 2018

@author: Nguyen Duong Thanh
"""
from math import sqrt; from itertools import count, islice

def isPrime(n):
    return n > 1 and all(n%i for i in islice(count(2), int(sqrt(n)-1)))

def isPrime2(n):
    
    if n < 2:
        return False
        
    for i in range(2,int(sqrt(n))+1):
        if n % i == 0:
            return False
        
    return True

def twoCompositeNum(a):
    num1 = num2 = 0
    for i in range(4, a // 2):
        if not isPrime(i) and not isPrime(a - i):
            num1 = i
            num2 = a - i
            break
    
    print(num1," ",num2)
    
def main():
    n = int(input())
    twoCompositeNum(n)
    
main()