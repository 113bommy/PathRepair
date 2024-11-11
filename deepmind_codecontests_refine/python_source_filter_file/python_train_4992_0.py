N = int(input())
for i in range(N):
    n,k = map(int,input().split())
    L = list(map(int,input().split()))
    if n <= k:
        print(0)
    else:
        A = []
        for j in range(1,N):
            A.append(L[i]-L[i-1])
        A.sort()
        A.reverse()
        S = L[N-1]-L[0]
        for l in range(k-1):
            S -= A[l]
        print(S)
