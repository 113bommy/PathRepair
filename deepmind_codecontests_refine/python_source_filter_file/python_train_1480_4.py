import sys

def Solve1(A, s, t):
    seq = list(range(s, t + 1))
    for i in seq: A[i] -= 1
    if any(A[i] < 0 for i in range(4)): return None
    if any(A[i] > 0 for i in range(4)):
        lo = min(i for i in range(4) if A[i] > 0)
        hi = max(i for i in range(4) if A[i] > 0)
        if any(A[i] == 0 for i in range(lo, hi)): return None
        k = s
        while k > lo:
            if A[k - 1] == 0 or A[k] == 0: return None
            j = seq.index(k)
            seq[j:j] = [k, k - 1]
            A[k] -= 1; A[k - 1] -= 1; k -= 1
        k = t
        while k < hi:
            if A[k] == 0 or A[k + 1] == 0: return None
            j = seq.index(k)
            seq[j:j] = [k, k + 1]
            A[k] -= 1; A[k + 1] -= 1; k += 1
    ops = [0, 0, 0]
    # X[0] == A[0], X[0] + X[1] == A[1], X[1] + X[2] == A[2], X[2] == A[3]
    ops[0] = A[0]
    ops[1] = A[1] - ops[0]
    ops[2] = A[2] - ops[1]
    for x in ops:
        if x < 0: return None
    if ops[2] != A[3]: return None
    ans = []
    for x in seq:
        ans.append(x)
        if x < 3 and ops[x] > 0:
            ans.extend([x + 1, x] * ops[x])
            ops[x] = 0
        elif x > 0 and ops[x - 1] > 0:
            ans.extend([x - 1, x] * ops[x - 1])
            ops[x - 1] = 0
    return ans

def Solve(A):
    if A[1] == 0 and A[0] > 0 and A[2] + A[3] > 0: return None
    if A[2] == 0 and A[3] > 0 and A[0] + A[1] > 0: return None
    for s in range(4):
        for t in range(s, 4):
            att = Solve1(A[:], s, t)
            if att is not None: return att
    return None

def SolvePrint(A):
    ans = Solve(A)
    if ans is None:
        print('NO')
    else:
        print('YES')
        print(' '.join(str(x) for x in ans))

def Test():
    for i in range(10000):
        t = i
        a = []
        for _ in range(4):
            a.append(t % 10)
            t //= 10
        print(a, end=': ')
        SolvePrint(a)
    print('Done')

def Main():
    A = list(map(int, sys.stdin.readline().split()))
    SolvePrint(A)

Test()
#Main()
