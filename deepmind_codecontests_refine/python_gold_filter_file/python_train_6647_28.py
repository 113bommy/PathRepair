N = int(input())
A = [int(_) for _ in input().split()]

def solve(N, A):
    k = N * (N + 1) // 2
    s = sum(A)
    if s % k > 0:
        return False
    m = s // k
    # print(k, s, m)
    rs = []
    for i in range(N):
        p = A[i - 1]
        q = A[i]
        delta = q - p
        y = m - delta
        # print(p, q, delta, y, N)
        if y % N > 0:
            return False
        x = y // N
        rs.append(x)
    # print("*", rs)
    R = 0
    for i in range(N):
        x = rs[i]
        l = (N - i) % N + 1
        R += l * x
    # print(1, R)
    if R != A[0]:
        return False
    for i in range(1, N):
        R += m - rs[i]
        R -= rs[i] * (N - 1)
        # print(i, R)
        if R != A[i]:
            return False
    return True

def solve(N, A):
    k = N * (N + 1) // 2
    s = sum(A)
    if s % k > 0:
        return False
    m = s // k
    for i in range(N):
        x = A[i - 1] - A[i] + m
        if x < 0 or (x % N) > 0:
            return False
    return True

if solve(N, A):
    print("YES")
else:
    print("NO")
