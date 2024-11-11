import sys

n = int(input())
A = input().split()
A = [int(i) for i in A]
S = input()

L = -1000000000
R = 1000000000

for i in range(4, n):
    if S[i - 1] == S[i - 2] == S[i - 3] == S[i - 4] == '0' and S[i] == '1':
        L = max(max(A[i], A[i - 1], A[i - 2], A[i - 3], A[i - 4]) + 1, L)
    elif S[i - 1] == S[i - 2] == S[i - 3] == S[i - 4] == '1' and S[i] == '0':
        R = min(min(A[i], A[i - 1], A[i - 2], A[i - 3], A[i - 4]) - 1, R)
    elif S[i - 1] == S[i - 2] == S[i - 3] == S[i - 4] == '0' and S[i] == '0':
        L = min(min(A[i], A[i - 1], A[i - 2], A[i - 3], A[i - 4]), L)
    elif S[i - 1] == S[i - 2] == S[i - 3] == S[i - 4] == '1' and S[i] == '1':
        R = max(max(A[i], A[i - 1], A[i - 2], A[i - 3], A[i - 4]), R)

print('{} {}'.format(L, R))
