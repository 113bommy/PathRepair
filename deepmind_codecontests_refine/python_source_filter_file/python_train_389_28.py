from math import gcd
N = int(input())
A = list(map(int,input().split()))

g = 0
for a in A:
    g = gcd(g,a)
if g > 1:
    print('not coprime')
    exit()

MAXA = 10**6
B = [0] * (MAXA+1)
for a in A:
    if a==1: continue
    if B[a]:
        print('setwise coprime')
        exit()
    B[a] = 1

for n in range(2,MAXA+1):
    c = 0
    for m in range(n,MAXA+1,n):
        c += B[m]
        if c > 1:
            print('setwise coprime')
            exit()

print('pairwise coprime')