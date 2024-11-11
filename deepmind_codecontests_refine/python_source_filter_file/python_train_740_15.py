from collections import Counter
n = int(input())
m = list(map(int, input().split()))
r = [[0 for _ in range(n)] for _ in range(n)]
if n % 2 == 0:
    c = Counter(m)
    ans = []
    for x in c:
        if c[x] % 4 != 0:
            print('NO')
            break
        else:
            ans.extend([x]*(c[x]//4))
    else:
        x = (n // 2) * (n // 2)
        i = 0
        j = 0
        for x in ans:
            r[i][j] = x
            r[i][-j-1] = x
            r[-i-1][j] = x
            r[-i-1][-j-1] = x
            j += 1
            if j == 2:
                j = 0
                i += 1
        print('YES')
        for x in r:
            print(*x)
else:
    c = Counter(m)
    cc = 0
    index = 0
    for x in c:
        if c[x] % 2 != 0:
            cc += 1
            index = x
    if cc != 1:
        print('NO')
    else:
        r[n//2][n//2] = index
        c[index] -= 1
        if c[index] == 0:
            del c[index]
        count = n//2+n//2
        used = []
        ans = []

        s = sum([c[x] for x in c])-count*2
        if s % 4 != 0:
            print('NO')
        else:
            ans = []
            used = []
            for x in c:
                if c[x] % 4 != 0:
                    count -= 1
                    ans.append(x)
                    c[x] -= 2
                    if c[x] == 0:
                        used.append(x)
                if count == 0:
                    break
            for x in used:
                del c[x]
            used = []
            if count > 0:
                for x in c:
                    if c[x] <= count*2:
                        used.append(x)
                        ans.extend([x]*(c[x]//2))
                        count -= c[x]//2
                    else:
                        c[x] -= count*2
                        ans.extend([x]*count)
                        count = 0
                    if count == 0:
                        break

            for x in used:
                del c[x]
            f = False
            i = 0
            for x in ans:
                if not f:
                    r[n//2][i] = x
                    r[n//2][-i-1] = x
                    f = True
                else:
                    r[i][n//2] = x
                    r[-i-1][n//2] = x
                    f = False
                    i += 1
            ans = []
            for x in c:
                if c[x] % 4 != 0:
                    print('NO')
                    break
                else:
                    ans.extend([x] * (c[x] // 4))
            else:
                x = (n // 2) * (n // 2)
                i = 0
                j = 0
                for x in ans:
                    r[i][j] = x
                    r[i][-j - 1] = x
                    r[-i - 1][j] = x
                    r[-i - 1][-j - 1] = x
                    j += 1
                    if j == 2:
                        j = 0
                        i += 1
                print('YES')
                for x in r:
                    print(*x)

