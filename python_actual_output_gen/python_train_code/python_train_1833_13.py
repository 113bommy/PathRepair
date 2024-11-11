import sys, math, collections, heapq, itertools
F = sys.stdin
def single_input(): return F.readline().strip("\n")
def line_input(): return F.readline().strip("\n").split()
def gcd(a, b):
    a, b = max(a, b), min(a, b)
    while a % b > 0: a, b = b, a % b
    return b
  
def solve():
    N = int(single_input())
    sum = 0
    smallestB = 10 ** 10
    for i in range(N):
        a, b = map(int, line_input())
        sum += a
        if a > b: smallestB = min(smallestB, b)
    print(sum - smallestB)
    return 0
  
if __name__ == "__main__":
    solve()