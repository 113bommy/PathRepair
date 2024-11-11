N = int(input())
X = input().strip()
C = X.count("1")
D = int(X, 2)
Mm, Mp = 0, D % (C+1)
if C > 0:
    Mm = D % (C-1)

p = [0]*(2*10**5+2)
for i in range(1, len(p)):
    n = i
    while True:
        b = bin(n).count("1")
        if b <= 0:
            break
        p[i] += 1
        n = n % b

for i in range(1, N+1):
    c = C
    if X[i-1] == "1":
        c -= 1
        if c == 0:
            print(0)
            continue
        m = Mm
        d = pow(2, N-i, c)
        d = (m-d+c) % c
    else:
        c += 1
        m = Mp
        d = pow(2, N-i, c)
        d = (m+d) % c

    print(p[d]+1)
