import sys
n = int(sys.stdin.readline().strip())
A = [int(i) for i in sys.stdin.readline().strip().split()]


k = 0
for i in range(1, n-1):
    if A[i - 1] == A[i + 1] == 0 and A[i]:
        A[i + 1] = 0
        k = k + 1
print(k)