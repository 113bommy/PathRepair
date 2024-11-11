N, Q = [int(x) for x in input().split()]
S = input()
TD = []
for _ in range(Q):
    t, d = input().split()
    TD.append((t, d))


def isDead(targetIdx):
    ti = targetIdx
    for t, d in TD:
        if t == S[ti]:
            if d == 'L':
                ti -= 1
                if ti == -1:
                    return -1
            else:
                ti += 1
                if ti == N:
                    return +1
    return 0


l, t, r = -1, N // 2, N

while r - l > 1:
    t = (l + r) // 2
    if isDead(t) == -1:
        l = t
    else:
        r = t

L = l
if L == 0 and isDead(0) == 0:
    L -= 1

l, t, r = 0, N // 2, N - 1

while r - l > 1:
    t = (l + r) // 2
    if isDead(t) == +1:
        r = t
    else:
        l = t

R = r
if R == N - 1 and isDead(N - 1) == 0:
    R += 1

print(R - L - 1)

# print((L, R))
# print([isDead(t) for t in range(N)])
