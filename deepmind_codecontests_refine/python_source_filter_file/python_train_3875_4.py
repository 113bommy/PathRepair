MOD = 10**18+13
import sys
readline = sys.stdin.readline         
from random import randrange
def compress(L):
    L2 = list(set(L))
    L2.sort()
    C = {v : k for k, v in enumerate(L2, 1)}
    return L2, C
 
N = int(readline())
 
T = set()
 
L = [None]*N
for i in range(N):
    L[i] = tuple(map(int, readline().split()))
    T |= set(L[i])
t2, C = compress(list(T))
Z = len(t2)
L = [[j] + [C[L[j][i]] for i in range(4)] for j in range(N)]

seed = []
while len(set(seed)) != N:
    seed = [randrange(1, MOD) for _ in range(N)]
S1 = [0]*(Z+2)
S2 = [0]*(Z+2)
S3 = [0]*(Z+2)
S4 = [0]*(Z+2)         
p1 = [0]*N
p2 = [0]*N
for i in range(N):
    j, s1, t1, s2, t2 = L[i]
    S1[s1] += seed[j]
    S2[t1] += seed[j]
    S3[s2] += seed[j]
    S4[t2] += seed[j]

for i in range(1, Z+1):
    S1[i] = (S1[i] + S1[i-1])%MOD
    S2[i] = (S2[i] + S2[i-1])%MOD
    S3[i] = (S3[i] + S3[i-1])%MOD
    S4[i] = (S4[i] + S4[i-1])%MOD

for i in range(N):
    j, s1, t1, s2, t2 = L[i]
    p1[j] = (S2[s1] - S1[t1])%MOD
    p2[j] = (S4[s2] - S3[t2])%MOD
print('YES' if all(a == b for a, b in zip(p1, p2)) else 'NO')
