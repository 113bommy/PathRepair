h,w,n = map(int,input().split())
s = list(map(int,input().split()))
S = input()
T = input()

def YES(b):
    if not b:
        print('YES')
    else:
        print('NO')
    exit(0)
    return

R = [s[0],s[0]]
C = [s[1],s[1]]

for i in range(n):
    if S[i] == 'L':
        C[0] -= 1
        if not (1 <= C[0] <= w):YES(True)
    elif S[i] == 'R':
        C[1] += 1
        if not (1 <= C[1] <= w):YES(True)
    elif S[i] == 'U':
        R[0] -= 1
        if not (1 <= R[0] <= h):YES(True)
    elif S[i] == 'D':
        R[1] += 1
        if not (1 <= R[0] <= h):YES(True)
    if T[i] == 'R' and C[0] != w:
        C[0] += 1
    elif T[i] == 'L' and C[1] != 1:
        C[1] -= 1
    elif T[i] == 'D' and R[0] != h:
        R[0] += 1
    elif T[i] == 'U' and R[1] != 1:
        R[1] -= 1
YES(False)
