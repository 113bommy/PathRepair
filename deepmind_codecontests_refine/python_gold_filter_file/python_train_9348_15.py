from math import factorial

N, K = map(int, input().split(" "))

l = [None]*2010
l[0] = 1
for i in range(1, 2010):
    l[i] = l[i-1]*i

for i in range(1, K+1):
    a = l[N-K+1] // l[i] // l[(N-K+1)-i]
    b = l[K-1] // l[i-1] // l[(K-1)-(i-1)]
    print(a*b % (10**9+7))