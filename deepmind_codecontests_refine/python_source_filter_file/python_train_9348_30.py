import math

n, k = map(int, input().split())

def cmb(n, r):
    return math.factorial(n)// (math.factorial(n-r) * math.factorial(r))

for i in range(k):
    if i <= k:
        print(cmb(n-k+1, i+1) * cmb(k-1, i) % 1000000007)
    else:
        print(0)