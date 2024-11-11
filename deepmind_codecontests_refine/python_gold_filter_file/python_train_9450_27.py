N, K = map(int,input().split())
A = list(map(int,input().split()))
A = [A[k]-1 for k in range(N)]
now = 0
for k in range(70):
    if (K>>k)&1 == 1:
        now = A[now]
    A = [A[A[l]] for l in range(N)]
print(now+1)
