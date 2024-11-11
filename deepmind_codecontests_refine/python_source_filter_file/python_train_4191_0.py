import sys
readline = sys.stdin.readline


def merge(A, B):
    res = A[:]
    for i in range(len(A)):
        if A[i]:
            for j in range(len(B)):
                if B[j]:
                    res[(i+j)%K] = 1
    return res

N, K = map(int, readline().split())
R = 0
B = 0

flag = False
table = [0]*K
table[0] = 1
for _ in range(N):
    r, b = map(int, readline().split())
    R += r
    B += b
    if r >= K and b >= K:
        flag = True
    elif r+b >= K:
        st, en = max(0, K-b), min(K, r)
        t2 = [0]*K
        for i in range(st, en+1):
            t2[i%K] = 1
        table = merge(table, t2)
if flag:
    print((R+B)//K)
elif (R//K + B//K == (R+B)//K):
    print((R+B)//K)
else:
    pr = R%K
    pb = B%K
    ans = R//K + B//K
    for i in range(K):
        if table[i]:
            if (pr-i)%K + (pb+pr-i)%K < K:
                ans += 1
                break
    print(ans)