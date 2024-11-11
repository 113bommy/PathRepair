N,K = map(int,input().split())
A = list(map(int,input().split()))
S = []
for i in range(N):
    t = i
    s = 0
    for j in range(t,N):
        s += A[j]
        S.append(s)
n = len(S)
x = 0
for i in range(40):
    m = 40 - i
    t = m - 1
    k = 0
    for j in range(n):
        if (x+2**t)&S[j] == x+2**t:
            k += 1
    if k >= K:
        x += 2**t
print(x)