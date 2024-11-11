import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

from collections import deque
mm = (1 << 17) - 1
T = int(input())
for _ in range(T):
    N = int(input())
    LR = [0] * N
    for i in range(N):
        l, r = map(int, input().split())
        LR[i] = (l << 17) + r
    
    X = [[] for i in range(N)]
    for i in range(N-1):
        x, y = map(int, input().split())
        x, y = x-1, y-1 # 1-indexed
        X[x].append(y)
        X[y].append(x)

    P = [-1] * N
    Q = deque([0])
    R = []
    while Q:
        i = deque.popleft(Q)
        R.append(i)
        for a in X[i]:
            if a != P[i]:
                P[a] = i
                X[a].remove(i)
                deque.append(Q, a)
    
    if 0:
        print("X =", X) # �q���X�g
        print("P =", P) # �e
        print("R =", R) # �g�|���W�J���\�[�g
    
    LL = [0] * N
    RR = [0] * N
    for i in R[1:][::-1]:
        p = P[i]
        lr = LR[i]
        l, r = lr >> 17, lr & mm
        lr = LR[p]
        ll, rr = lr >> 17, lr & mm
        LL[p] += max(abs(l - ll) + LL[i], abs(r - ll) + RR[i])
        RR[p] += max(abs(l - rr) + LL[i], abs(r - rr) + RR[i])
    print(max(LL[0], RR[0]))

