import math 
N = int(input())
A = list(map(int, input().split()))
m = [0] * int(1e6+1)
for i in range(N):
    m[A[i]] += 1
pw = True
for p in range(2, N+1):
    c = 0
    for i in range(p, len(m), p):
        c += m[i]
    if c > 1:
        pw = False
        break
if pw:
    print('pairwise coprime')
    exit()
d = A[0]
for i in range(N):
    d = math.gcd(d, A[i])
if d == 1:
    print('setwise coprime')
else:
    print('not coprime')
