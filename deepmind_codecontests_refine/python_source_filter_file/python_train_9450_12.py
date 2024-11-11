N,K = map(int,input().split())
A = list(map(int,input().split()))
B = [True]*N
C = [1]
now = 0
while B[now]:
    B[now] = False
    now = A[now] - 1
    C.append(now+1)
start = C.index(C[-1])
D = C[start:-1]
L = len(D)
if K < start:
    print(C[k])
else:
    K -= start
    K %= L
    print(D[K])