from statistics import median

N = int(input())
A = [0] * N
B = [0] * N
for c in range(N):
    A[c], B[c] = map(int, input().split())

A_med = median(A)
B_med = median(B)

if N % 2 == 0:
    print(round(2 * (B_med - A_med) + 1))
else:
    print(B_med - A_med + 1)
