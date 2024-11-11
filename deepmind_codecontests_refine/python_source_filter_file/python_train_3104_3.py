mod = 10**9+7
n, m = map(int, input().split())
a = sorted(list(map(int, input().split())), reverse=True)
b = sorted(list(map(int, input().split())), reverse=True)

if len(a) != len(set(a)) or len(b) != len(set(b)):
    print(0)
    exit()

#a = set(a)
#b = set(b)

c = 1
N = 0
M = 0
for k in range(n*m, 0, -1):
    if k in a and k in b:
        N += 1
        M += 1
    elif k in a:
        c *= M
        N += 1
    elif k in b:
        c *= N
        M += 1
    else:
        c *= M*N - (m*n-k)
    c %= mod

print(c)
