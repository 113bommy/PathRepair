from collections import Counter
import string
import math
import bisect
#import random
import sys
# sys.setrecursionlimit(10**6) 

from fractions import Fraction


def array_int():
    return [int(i) for i in sys.stdin.readline().split()]
def vary(arrber_of_variables):
    if arrber_of_variables==1:
        return int(sys.stdin.readline())
    if arrber_of_variables>=2:
        return map(int,sys.stdin.readline().split()) 
def makedict(var):
    return dict(Counter(var))
def isSubSequence(str1, str2):
    m = len(str1)
    n = len(str2)
 
    j = 0    # Index of str1
    i = 0    # Index of str2
 
    # Traverse both str1 and str2
    # Compare current character of str2 with
    # first unmatched character of str1
    # If matched, then move ahead in str1
 
    while j < m and i < n:
        if str1[j] == str2[i]:
            j = j+1
        i = i + 1
 
    # If all characters of str1 matched,
    # then j is equal to m
    return j == m
testcases=vary(1)
for _ in range(testcases):
    primes=[1,4,6,8,9]
    nt=int(input())
    n=input()
    for i in n:
        if int(i) in primes:
            print(1)
            print(i)
            break
    else:
        st=['25','27','35','52','57','72','75','77','33','22','55','32']
        # print(2)
        for i in st:
            # print(i)
            if isSubSequence(i,n):
                print(2)
                print(i)
                break
        
