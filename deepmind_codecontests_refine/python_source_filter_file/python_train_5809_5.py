N,M = map(int,input().split())
A = list(map(int,input().split()))
A.sort()
B = [0 for i in range(10**5+1)]
S = [0]
s = 0
for i in range(N):
    B[A[i]] += 1
    s += A[i]
    S.append(s)
for i in range(2,10**5+2):
    B[-i] += B[-i+1]
d = 0
u = 2*10**5
for i in range(30):
    x = (u+d)//2
    if i == 30:
        x += 1
    m = 0
    for i in range(N):
        a = A[i]
        y = max(x - a,0)
        if y <= 10**5:
            m += B[y]
    if m >= M:
        d = x
    else:
        u = x
ans = 0
for i in range(N):
    a = A[i]
    x = max(d - a,0)
    if x <= 10**5:
        y = B[x]
    else:
        y = 0
    ans += (S[N] - S[N-y]) + a*y
ans -= (m-M)*d
print(ans)