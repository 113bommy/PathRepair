from math import factorial

def comb(a,b):
    return factorial(a) // factorial(b) // factorial(abs(a-b))

n, k = map(int, input().split())
for i in range(k):
    print(comb(k-1, i) * comb(n-k+1, i+1) % 1000000007)
