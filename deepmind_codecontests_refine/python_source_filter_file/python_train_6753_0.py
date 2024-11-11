import sys
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 7)

N,M = map(int,readline().split())
A = [int(x) for x in readline().split()]

OD = [x for x in A if x&1]
EV = [x for x in A if not x&1]

if len(OD) >= 3:
    print('Impossible')
    exit()

if len(A) == 1:
    if N == 1:
        B = [1]
    else:
        B = [1,N-1]
elif len(OD) == 0:
    B = A.copy()
    B[0] -= 1
    B[-1] += 1
elif len(OD) == 1:
    A = OD + EV
    B = A.copy()
    B[0] += 1
    B[-1] -= 1
else:
    A = OD[0] + EV + OD[-1]
    B = A.copy()
    B[0] += 1
    B[-1] -= 1
B = [x for x in B if x > 0]

print(*A)
print(len(B))
print(*B)