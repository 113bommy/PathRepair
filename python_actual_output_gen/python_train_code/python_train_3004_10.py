M,N = map(int,input().split())
A = list(map(int,input().split()))
A.sort()
if A[N - M] < 1/(4 * M):
    print("No")
else:
    print("Yes")