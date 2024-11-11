import sys

n = int(sys.stdin.readline().strip())
X = []
Y = []
for i in range (0, n):
    x, y = list(map(int, sys.stdin.readline().strip().split()))
    X.append(x)
    Y.append(y)
X.append(X[0])
Y.append(Y[0])
if n % 2 == 1:
    print("NO")
else:
    v = True
    m = n // 2
    for i in range (0, m):
        if X[i+1]-X[i] != X[i+m]-X[i+m+1]:
            v == False
        if Y[i+1]-Y[i] != Y[i+m]-Y[i+m+1]:
            v == False
    if v == True:
        print("YES")
    else:
        print("NO")