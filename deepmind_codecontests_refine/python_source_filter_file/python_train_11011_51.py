N,K = map(int,input().split())
A = list(map(int,input().split()))

A.append(0)

for j in range(K):
    B = [0] * (N+1)
    for i in range(N):
        B[max(i - A[i],0)] += 1
        B[min(i + A[i] + 1,N)] -= 1
    A = [0] * (N+1)
    a = 0
    for i in range(N):
        a += B[i]
        A[i] = a

print(*A[:-1])