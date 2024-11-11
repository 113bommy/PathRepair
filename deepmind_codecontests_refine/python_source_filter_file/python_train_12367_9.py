N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
BA = [(b, a) for (b, a) in zip(B, A)]
BA.sort()
B, A = list(map(list, zip(*BA)))  # BA.T
AI = [(a, i) for (i, a) in enumerate(A)]
AI.sort()
C, P = list(map(list, zip(*AI)))  # AI.T

def can_divide_cycle(P):
    start = P[0]
    ncycle = 1
    cur = start
    while P[cur] != start:
        cur = P[cur]
        ncycle += 1
    return ncycle < len(P)

vld = all(c <= b for (c, b) in zip(C, B)) \
    and (can_divide_cycle(P) or any(c >= b for (c, b) in zip(C[1:], B[:-1])))
print('Yes' if vld else 'No')
