import sys, heapq as h
input = sys.stdin.readline

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input().strip()

def listStr():
    return list(input().strip())

import collections as col
import math

"""
Longest matching prefix and suffix
Then for each start / end point, the longest palindrome going forwards and then longest palidrome going backwards
"""

def longest_prefix_suffix_palindrome(S,N):
    i = -1
    while i+1 <= N-i-2 and S[i+1] == S[N-i-2]:
        i += 1
    return i

def longest_palindromic_prefix(S): 
    tmp = S + "?"
    S = S[::-1] 
    tmp = tmp + S
    N = len(tmp) 
    lps = [0] * N
    for i in range(1, N): 
        #Length of longest prefix till less than i 
        L = lps[i - 1] 
        # Calculate length for i+1 
        while (L > 0 and tmp[L] != tmp[i]): 
            L = lps[L - 1] 
  
        #If character at current index and L are same then increment length by 1 
        if (tmp[i] == tmp[L]): 
            L += 1
        #Update the length at current index to L
        lps[i] = L
  
    return tmp[:lps[N - 1]]

def solve():
    S = getStr()
    N = len(S)
    i = longest_prefix_suffix_palindrome(S,N)
    #so S[:i+1] and S[N-i-1:] are palindromic
    if i >= N//2-1:
        return S
    #so there are least 2 elements between S[i] and S[N-i-1]
    new_str = S[i+1:N-i-1]
    longest_pref = longest_palindromic_prefix(new_str)
    longest_suff = longest_palindromic_prefix(new_str[::-1])[::-1]
    add_on = longest_pref if len(longest_pref) >= len(longest_suff) else longest_suff
    return S[:i+1] + add_on + S[N-i-1:]
    
for _ in range(getInt()):
    print(solve())
#print(solve())
    