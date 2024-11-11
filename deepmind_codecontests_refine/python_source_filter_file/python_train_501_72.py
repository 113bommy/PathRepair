N = input()
A = list(map(int, input().split()))
A.sort()
pritn(A[-1] - A[0])