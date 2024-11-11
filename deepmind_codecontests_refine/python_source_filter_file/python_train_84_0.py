import sys
input = sys.stdin.readline

"""
X定数だった。両極端な場合が合流する。
[0,L]上定数A、[R,X]上定数B、その間は線形
"""

X = int(input())
K = int(input())
R = [int(x) for x in input().split()]
Q = int(input())
TA = [tuple(int(x) for x in input().split()) for _ in range(Q)]

task = sorted([(r,-1) for r in R] + [(t,a) for t,a in TA])

L = 0
R = X
A = 0
B = X
dx = -1 # 初めは減る方
current = 0
answer = []
for t,a in task:
    # とりあえず上限を突破して落とす
    A += dx * (t-current)
    B += dx * (t-current)
    current = t
    if a != -1:
        # 体積の計算
        if a <= L:
            x = A
        elif a >= R:
            x = B
        else:
            x = A+(B-A)//(R-L)*(a-L)
        if x < 0:
            x = 0
        if x > X:
            x = X
        answer.append(x)
    else:
        dx = -dx
        if A < B:
            if A < 0:
                L += (-A)
                A = 0
            if B > X:
                R -= (B-X)
                B = X
            if A > X:
                A = X
                B = X
                L = 0
                R = 0
            if B < 0:
                A = 0
                B = 0
                L = 0
                R = 0
        elif A > B:
            if A > X:
                L += (A-X)
                A = X
            if B < 0:
                R -= (-B)
                B = 0
            if A < 0:
                A = 0
                B = 0
                L = 0
                R = 0
            if B > X:
                A = X
                B = X
                L = 0
                R = 0
        if R < L:
            R = L

print(*answer,sep='\n')