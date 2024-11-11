import sys
input = sys.stdin.readline

N, K = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

s = [];  t = [];
for a in A:
    if a < 0:
        t.append(a)
    else:
        s.append(a)

P = 10 ** 9 + 7
# 非負にできるか判定
S = len(s)
T = len(t)
ok = False
if S > 0:
    if N == K:
        ok = (T % 2 == 0)
    else:
        ok = True
else:
    ok = (K % 2 == 0)

ans = 1
if not ok:
    A.sort(key = lambda x: abs(x))  # 絶対値小→大
    for i in range(K):
        ans = ans * A[i] % P
else:   # 非負にできる
    s.sort()    # 小→大
    t.sort(reverse = True)  # 絶対値小→大
    if K % 2 == 1:
        ans *= s.pop() # 一番大きい正の数を確保

    p = []
    while len(s) >= 2:
        x = s.pop()
        x = x * s.pop() % P
        p.append(x)

    while len(t) >= 2:
        x = t.pop()
        x = x * t.pop()
        p.append(x)

    p.sort(reverse = True)
    for i in range(K // 2):
        ans = ans * p[i] % P


print(ans)