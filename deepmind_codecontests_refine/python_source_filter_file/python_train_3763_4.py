def gcd(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    return gcd(b, a % b)


def drobb(a, b):
    x = a // b
    a %= b
    g = gcd(a, b)

    return x, a // g, b // g


n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

D = {}

x = 0

for i in range(n):
    if A[i] == 0:
        if B[i] == 0:
            x += 1
        continue

    f = False

    if (A[i] > 0 and B[i] > 0) or (A[i] < 0 and B[i] < 0):
        f1 = True

    d = (drobb(abs(B[i]), abs(A[i])), f)
    if d in D.keys():
        D[d] += 1
    else:
        D[d] = 1

if len(D) != 0:
    print(max(D.values()) + x)
else:
    print(x)
