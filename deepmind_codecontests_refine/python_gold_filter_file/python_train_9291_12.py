def readintlst():
    return list(map(int, input().split(' ')))


def readcharlst():
    return list(input().split(' '))


def readn():
    return int(input())

for _ in range(readn()):
    n, k = readintlst()
    mat = [[0] * n for _ in range(n)]
    i = j = 0
    kk = k
    while k:
        k -= 1
        mat[i][j] = 1
        i+=1
        j+=1
        if i == n:
            i = 0
            j += 1
        j %= n

    # rmax, rmin = 0, n
    # for r in mat:
    #     sm = sum(r)
    #     rmax = max(rmax, sm)
    #     rmin = min(rmin, sm)
    # cmax, cmin = 0, n
    # for c in list(zip(*mat)):
    #     sm = sum(c)
    #     cmax = max(cmax, sm)
    #     cmin = min(cmin, sm)
    # ans = (rmax - rmin)**2 + (cmax - cmin)**2
    ans = 0 if kk % n == 0 else 2
    print(ans)
    for r in mat:
        print(''.join(map(str, r)))
