N, = map(int, input().split())
X = list(map(int, input().split()))
R = 0
for i in range(N):
    x = X[i]
    R = max(R, x)
    for j in range(i+1, N):
        y = X[j]
        R = max(R, x^y)
        for k in range(j+1, N):
            z = X[k]
            R = max(R, x^y^z)
print(R)
