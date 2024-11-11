N,M = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
a = [0 for i in range(N*M+1)]
b = [0 for i in range(N*M+1)]
da = [0 for i in range(N*M+1)]
db = [0 for i in range(N*M+1)]
mod = 10**9+7
for i in range(N):
    a[A[i]] += 1
    if da[A[i]] == 1:
        print(0)
        quit()
    da[A[i]] += 1
for i in range(M):
    b[B[i]] += 1
    if db[B[i]] == 1:
        print(0)
        quit()
    db[B[i]] += 1
for i in range(1,N*M+1):
    a[-i-1] += a[-i]
    b[-i-1] += b[-i]
ans = 1
for i in range(N*M):
    f = 0
    g = 0
    x = N*M - i
    y = i
    if da[x] == 1:
        f = 1
    if db[x] == 1:
        g = 1
    z = 1
    if f == 0:
        z = z*a[x]%mod
    if g == 0:
        z *= z*b[x]%mod
    if f+g == 0:
        z -= i
    if z <= 0:
        print(0)
        quit()
    else:
        ans = ans*z%mod
print(ans%mod)
