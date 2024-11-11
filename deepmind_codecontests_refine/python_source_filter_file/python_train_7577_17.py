from collections import Counter
mod = 1000000007


def inverse(a):
    return pow(a, mod - 2, mod)


def usearch(x, a):
    lft = 0
    rgt = len(a) + 1
    while rgt - lft > 1:
        mid = (rgt + lft) // 2
        if a[mid] <= x:
            lft = mid
        else:
            rgt = mid
    return lft


def main():
    n = int(input())
    s =input()
    frac = [1] * (n+1)
    for i in range(n):
        frac[i+1] = frac[i] * (i+1) % mod
    cnt = [0, 1]
    f = 0
    a = [0] * (2* n)
    a[-1] = 1
    for i in range(2*n-1):
        a[i] = f
        if s[i] == s[i+1]:
            f ^= 1

    ans = 1
    tmp = 0
    for i in range(2*n):
        if a[i] == 0:
            tmp += 1
        else:
            ans *= tmp
            ans %= mod
            tmp -= 1

    if len([i for i in a if i == 0]) == n and s[0] == s[-1] == 'B':
        print(ans * frac[n])
    else:
        print(0)

main()
