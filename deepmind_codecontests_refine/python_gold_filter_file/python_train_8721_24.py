N,M = map(int,input().split())
A = list(map(int,input().split()))
A.sort()
if A[N - M] < sum(A)/(4 * M):
    print("No")
else:
    print("Yes")