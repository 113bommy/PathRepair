def solve(A, B):
    from math import sqrt
    M = A * B
    cnt = 0

    x, y = A, B
    if y - x >= 1:
        z = int(sqrt(M))
        x = z
        y = M // x if M % x else M // x - 1
        cnt += z - x
    cnt += y - 1

    x, y = A, B
    if y - x >= 1:
        z = int(sqrt(M))
        x = z
        y = M // x if M % x else M // x - 1
        cnt += z - x
    cnt += y - 1
    
    return cnt


Q = int(input())
Query = [tuple(map(int, input().split())) for _ in range(Q)]

for A, B in Query:
    print(solve(A, B))
