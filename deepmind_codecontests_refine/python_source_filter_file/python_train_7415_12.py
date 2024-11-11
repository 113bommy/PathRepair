from copy import deepcopy

mod = 998244353

if __name__=='__main__':
    [n, k] = [int(x) for x in input().split()]
    p = [int(x) for x in input().split()]
    bak = deepcopy(p)
    bak.sort(reverse = True)
    visited = set(bak[:k])
    cnt = []

    j = 1
    for i in range(n):
        if (p[i] in visited):
            j = i
            break

    for i in range(j + 1, n):
        if (p[i] in visited):
            cnt.append(i - j);
            j = i

    prod = 1
    mv = 0
    for x in cnt:
        prod *= x

    for i in range(k):
        mv += bak[i]
    print( mv % mod, prod % mod)