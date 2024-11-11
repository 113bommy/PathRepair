N,K = map(int,input().split())
A = list(map(int,input().split()))

for k in range(1,min(K+1,50)):
    B = [0]*N
    for i in range(N):
        l = max(0,i-A[i])
        r = min(N-1,i+A[i])
        B[l] += 1
        if r+1 < N:
            B[r+1] -= 1
            
    for i in range(1,N):
        B[i] += B[i-1]
    A = B
print(*A)