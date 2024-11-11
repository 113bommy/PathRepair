ef multiply(x, y):
    return (x * y) % mod


def power(x, y):
    if y == 0:
        return 1
    elif y == 1:
        return x
    elif x == 1:
        return 1
    elif x == 0:
        return 0
    else:
        # print(mod)
        tmp = power(x, y // 2)
        return (multiply(tmp, tmp) * [1, x][y % 2]) % mod


N = int(input())
A = list(map(int, input().split()))

mod = 10 ** 9 + 7

plist = [0]
nfact = 1
N
tmp = 0
for i in range(1, N):
    tmp = (tmp + power(i + 1, mod - 2)) % mod
    nfact = (nfact * (i + 1)) % mod
    plist.append(tmp)

ans = 0
# print(plist)
# print(nfact)
for i, a in enumerate(A):
    # print(i, N - i - 1, N)
    tmp = (1 + plist[i] + plist[N - i - 1]) % mod
    ans = (ans + multiply(multiply(a, tmp), nfact)) % mod

print(ans)