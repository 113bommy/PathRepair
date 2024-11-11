import sys
import math
import collections
import bisect
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
def isSubSequence(str1, str2):
    m = len(str1)
    n = len(str2)
    j = 0  # Index of str1
    i = 0  # Index of str2
    while j < m and i < n:
        if str1[j] == str2[i]:
            j = j + 1
        i = i + 1
    return j == m
for t in range(1):
    s1=get_string()
    s2=get_string()
    string1=list(s1)
    string2=list(s2)
    counter1=collections.Counter(string1)
    counter2=collections.Counter(string2)
    removed=0
    np=0
    for i in counter2:
        if i in counter1:
            val=(counter1[i]-counter2[i])
            if val>0:
                removed+=1
            elif val<0:
                np+=1
        else:
            np+=1
    if sorted(string1)==sorted(string2):
        print("array")
    elif np>0:
        print("need tree")
    else:
        if isSubSequence(s2,s1):
            print("automaton")
        else:
            print("both")