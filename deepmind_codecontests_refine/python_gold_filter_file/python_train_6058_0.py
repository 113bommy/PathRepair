import sys

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
if n == 1:
    print(0)
    sys.exit(0)

X = []
for i in range(n):
    X.append((A[i], B[i]))
X.sort()
Y = []
S = set()
ans = 0
for i in range(n):
    if (i < n - 1 and X[i][0] == X[i + 1][0]) or (i > 0 and X[i][0] == X[i - 1][0]):
        ans += X[i][1]
        S.add(X[i][0])
    else:
        Y.append(X[i])
for a, b in Y:
    T = False
    for s in S:
        if a & s == a:
            T = True
            break
    if T:
        ans += b
print(ans)