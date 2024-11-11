from math import *
ans = dict()
ans[(0,0,0)] = ans[(0,0,1)] = ans[(0,1,1)] = 4
ans[(1,1,1)] = ans[(0,0,2)] = ans[(0,1,2)] = ans[(1,2,0)] = 5
ans[(1,1,2)] = ans[(0,2,2)] = 6
ans[(1,2,2)] = 7
ans[(2,2,2)] = 8
dist = lambda A, B: ((A[0] - B[0]) ** 2 + (A[1] - B[1]) ** 2) ** 0.5
belong = lambda P, i: abs(dist(P, (c[i][0], c[i][1])) - c[i][2]) < 1e-9
 
def intersection(c1, c2):
    O1 = c1[0], c1[1]
    O2 = c2[0], c2[1]
    r1, r2 = c1[2], c2[2]
    OO = O2[0]- O1[0], O2[1]- O1[1]
    d = dist(O1, O2)
    if d > r1 + r2 or d < abs(r1 - r2): return []
    alp = atan2(OO[1], OO[0])
    phi = acos((r1**2 + d**2 - r2**2) / (2 * r1 * d))
    P1 = (r1 * cos(alp + phi) + O1[0], r1 * sin(alp + phi) + O1[1])
    P2 = (r1 * cos(alp - phi) + O1[0], r1 * sin(alp - phi) + O1[1])
    return [P1] if dist(P1, P2) < 1e-9 else [P1, P2]
 
def solve():
    if n == 1: return 2
    if n == 2: return 3 + len(intersection(c[0], c[1])) == 2
    inter = [0, 0, 0]
    p = []
    for i in range(3):
        for j in range(i + 1, 3):
            cur = intersection(c[i], c[j])
            p += cur
            inter[i + j - 1] += len(cur)
    cnt = sum(int(sum(belong(P, i) for i in (0, 1, 2)) == 3) for P in p)
    return ans[tuple(sorted(inter))] - cnt // 3
 
n = int(input())
c = [tuple(map(int, input().split())) for i in range(n)]
print(solve())