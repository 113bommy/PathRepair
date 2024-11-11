a, b = map(int, input().split())
A = list(map(int, input().split()))
A.append(-1)
B = []
Z = []
AN = []
x, y = A[0], A[1]
for i in range(a - 1):
    Z.append((x, y))
    if x > y:
        B.append(y)
        y = A[i + 2]
    else:
        B.append(x)
        x, y = y, A[i + 2]
for i in range(b):
    w = int(input())
    if w < len(Z):
        AN.append(Z[w - 1])
    else:
        w = w % len(B)
        AN.append((x, B[w - 1]))
for W in AN:
    print(*W)