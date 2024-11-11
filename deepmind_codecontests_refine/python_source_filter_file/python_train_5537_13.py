a1 = int(input())
a2 = int(input())
k1 = int(input())
k2 = int(input())
N = int(input())
m2 = 0
t = N
if(k1 < k2):
    m2 += min(a1, N // k1)
    t -= (min(a1, N // k1) * k1)
    m2 += min(a2, t // k2)
else:
    m2 += min(a2, N // k2)
    t -= (min(a2, N // k2) * k2)
    m2 += min(a1, t // k1)
N -= (a1 * (k1 - 1) + a2 * (k2 - 1))
print(min(a1 + a2, N), m2)
