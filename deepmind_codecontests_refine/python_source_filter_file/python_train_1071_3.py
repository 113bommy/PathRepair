import sys
from math import factorial # ,comb
from collections import Counter
inline = sys.stdin.readline

def comb(n, k):
    return int(factorial(n) / factorial(k) / factorial(n-k))

def solution(arr, k):
    arr.sort(reverse=True)
    num = arr[k-1]
    n = Counter(arr)[num]
    k = Counter(arr[:k])[num]
    return comb(n, k) % (10**9 + 7)
    
T = int(inline().strip())
for t in range(T):
    _, k = map(int,inline().strip().split())
    arr = list(map(int, inline().strip().split()))
    print(solution(arr, k))