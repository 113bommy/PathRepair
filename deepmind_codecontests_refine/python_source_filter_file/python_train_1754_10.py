N, A, B, C, D = map(int, input().split())
lb, ub = A, A
for _ in range(1, N):
    if (lb + ub) / 2 < B:
        lb, ub = lb + C, ub + D
    else:
        lb, ub = lb - D, ub - C
if lb <= B <= ub:
    print('Yes')
else:
    print('No')