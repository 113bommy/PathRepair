import sys
pin = sys.stdin.readline

T = int(pin())
pin()
for t in range(T):
    A = [*map(int,pin().split())]
    B = [*map(int,pin().split())]
    F = [*map(int,pin().split())]
    pin()
    ans = abs(A[0]-B[0]) + abs(A[1]-B[1])
    if A[0] == B[0] == F[0] and (A[1] <= F[1] <= B[1] or A[1] >= F[1] >= B[1]): ans += 2
    if A[1] == B[1] == F[1] and (A[0] <= F[0] <= B[0] or A[0] >= F[0] >= B[0]): ans += 2
    print(ans)