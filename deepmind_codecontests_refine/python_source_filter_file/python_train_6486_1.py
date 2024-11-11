def one_mnogetel(a):
    for i in range(2, int(a ** 0.5) + 1):
        if a % i == 0:
            return i
    return a

def F(a):
    ans = 1
    while one_mnogetel(a) != a:
        g = one_mnogetel(a)
        if ans % g == 0:
            ans //= g
        else:
            ans *= g
        a = a // g
    if ans % a == 0:
        ans //= a
    else:
        ans *= a
    return ans

#print(F(18))

for _ in range(int(input())):
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    B = []
    for i in range(len(A)):
        B.append((F(int(A[i])), i))
        A[i] = (A[i], -10)
    B.sort()
    #print(B)
    for i in range(1, len(B)):
        if B[i][0] == B[i - 1][0]:
            A[B[i][1]] = (A[B[i][1]][0], B[i - 1][1])
    Ans = 0
    last = -1
    #print(A)
    for i in range(1, len(A)):
        if last < A[i][1]:
            Ans += 1
            last = i
    print(Ans + 1)
