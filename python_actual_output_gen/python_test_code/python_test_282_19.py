N, X = map(int, input(). split())
a, p = [1], [1]

for n in range(N):
    a.append(a[n]*2 + 3)
    p.append(p[n]*2 + 1)

def xmas(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif 0 <= X <= 1 + a[N-1]:
        return xmas(N-1, X-1)
    else :
        return p[N-1] + 1 + xmas(N-1, X-(a[N-1]+2))

print(xmas(N, X))