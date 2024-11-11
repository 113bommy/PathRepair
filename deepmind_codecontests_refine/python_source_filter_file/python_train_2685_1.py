N, M = map(int, input().split())
A = list(set(map(int, input().split())))

def gcd(m, n):
    if n == 0:
        return m
    return gcd(n, m % n)

LCM = A[0]
for a in A:
    LCM = LCM * a // gcd(LCM, a)

K = max(A)
for X in range(K // 2, M + 1, K):
    for a in A:
        if (X - a // 2) % 2 != 0:
            break
    else:
        print((M - X) // LCM + 1)
        exit()
print(0)
