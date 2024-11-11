import collections
import itertools
from functools import reduce

mod = (10 ** 9) + 7


def permutationbysum():
    for _ in range(int(input())):
        num, l, r, achieve = map(int, input().split())
        k = r - l + 1
        if (k * (k + 1)) // 2 <= achieve <= (k * (num * 2 + 1 - k)) // 2:
            outpos = (r) % num
            inpos = l - 1
            ans = [0] * num
            for i in range(num, 0, -1):
                if achieve - i > 0 or (achieve - i == 0 and inpos == r - 1):
                    achieve -= i
                    ans[inpos] = i
                    inpos += 1
                else:
                    ans[outpos] = i
                    outpos += 1
                    outpos %= num
            print(*ans)
        else:
            print(-1)


# permutationbysum()

def peaks():
    for _ in range(int(input())):
        num, peak = map(int, input().split())
        pos = 1
        rpos = num
        ans = []
        now = 0
        if num == 1:
            if not peak:
                print(1)
            else:
                print(-1)
            continue
        if num == 2:
            if peak:
                print(-1)
            else:
                print(1, 2)
            continue
        added = 0
        while rpos + 1 != pos:
            if not peak:
                while pos <= rpos:
                    ans.append(pos)
                    pos += 1
                break
            if not now:
                ans.append(pos)
                pos += 1
            else:
                ans.append(rpos)
                rpos -= 1
                if num - added != 1:
                    peak -= 1
            added += 1
            now = 1 - now
        if peak:
            print(-1)
            continue
        print(*ans)


# peaks()
import sys

input = sys.stdin.readline


def addone():
    for _ in range(int(input())):
        num, changes = input().split()
        l = collections.deque(sorted([int(i) for i in num]))
        perm = collections.deque()
        changes = int(changes)
        cd = 0
        ans = len(num)
        while True:
            nextnum = l.pop()
            while perm and perm[-1] == nextnum:
                l.append(perm.pop())
            c = (10 - nextnum) - cd
            changes -= c
            cd += c
            if changes >= 0:
                if not c:
                    perm.appendleft(1 - cd)
                    l.appendleft(-cd)
                else:
                    l.appendleft(1 - cd)
                    l.appendleft(-cd)
                ans += 1
            else:
                break
        print(ans % 1000000007)


# addone()

import math


def andsequences():
    def mapping(num):
        nonlocal mnum
        nonlocal c
        num = int(num)
        if num < mnum:
            mnum = num
            c = 1
        elif num == mnum:
            c += 1
        return num

    mod = 1000000007
    for _ in range(int(input())):
        mnum = float('inf')
        c = 0
        num = int(input())
        l = list(map(mapping, input().split()))
        for i in l:
            if mnum & i != mnum:
                print(0)
                break
        else:
            if c == 1:
                print(0)
            else:
                print((math.factorial(num - 2) * (c - 1) * c) % mod)


# andsequences()

def numberdigit():
    n = ((10 ** 5) * 2)
    l = [0] * 11
    mod = 10 ** 9 + 7
    l[0] = l[1] = l[2] = l[3] = l[4] = l[5] = l[6] = l[7] = l[8] = 2
    l[9] = 3
    l[10] = 4
    for i in range(11, n):
        l.append((l[i - 10] + l[i - 9]) % mod)
    for _ in range(int(input())):
        num, c = input().split()
        c = int(c)
        ans = 0
        for i in num:
            i = int(i)
            if 10 - i > c:
                ans += 1
            else:
                ans += l[c - (10 - i)]
        print(ans % mod)


# numberdigit()

def mushroom():
    people, t1, t2, percent = map(int, input().split())
    l = []
    percent = 1 - percent * 0.01
    for i in range(1, people + 1):
        s, s1 = map(int, input().split())
        l.append([i, max(s * t1 * percent + s1 * t2, s1 * t1 * percent + s * t2)])
    l.sort(key=lambda x: (x[1]), reverse=True)
    for i in l:
        i[1] = "{:.2f}".format(i[1])
        print(*i)


# mushroom()

def escape():
    prins = int(input())
    dra = int(input())
    start = int(input())
    pack = int(input())
    c = int(input())
    speeddiff = dra - prins
    if speeddiff <= 0:
        return 0
    pd = start * prins
    ans = 0
    while pd < c:
        hs = pd / speeddiff
        pd += prins * hs
        if pd >= c:
            break
        time = pd / dra
        time += pack
        pd += prins * time
        ans += 1
    return ans


# print(escape())

def perm():
    def high(n, k):
        return k * (2 * n - k + 1) // 2

    def low(k):
        return k * (k + 1) // 2

    for _ in range(int(input())):
        num, lef, rig, s = map(int, input().split())
        k = rig - lef + 1
        rig, lef = rig - 1, lef - 1
        if not high(num, k) >= s >= low(k):
            print(-1)
            continue
        l = [0] * num
        lp = lef
        rp = lef - 1
        for i in range(num, 0, -1):
            if high(i, k) >= s and s - i >= low(k - 1) and k:
                l[lp] = i
                lp += 1
                s -= i
                k -= 1
            else:
                l[rp] = i
                rp -= 1
        if k:
            print(-1)
        else:
            print(*l)


# perm()


def newcom():
    for _ in range(int(input())):
        days, price = map(int, input().split())
        dl = input().split()
        worth = input().split()
        worth.append(0)
        ans = float('inf')
        req = 0
        left = 0
        for i in range(days):
            a = int(dl[i])
            w = int(worth[i])
            ans = min(ans, req + max(0, price - left + a - 1) // a)
            ns = max(0, w - left + a - 1) // a
            req += ns + 1
            left += a * ns - w
        print(ans)


# newcom()


def perfectsq():
    for _ in range(int(input())):
        n = input()
        for i in input().split():
            sq = math.sqrt(int(i))
            if sq != int(sq):
                print("YES")
                break
        else:
            print("NO")


# perfectsq()

def and0big():
    for _ in range(int(input())):
        l, k = map(int, input().split())
        print(l ** k % mod)


# and0big()

import math


def mod1p():
    n = int(input())
    ans = dict()
    p = 1
    for i in range(1, n):
        if math.gcd(i, n) == 1:
            ans[str(i)] = True
            p = (p * i) % n
    if p == 1:
        print(len(ans))
        print(' '.join(ans.keys()))
    else:
        ans.pop(str(p))
        print(len(ans))
        print(' '.join(ans.keys()))


# mod1p()

def shorttask():
    num = 10000100
    l = [-1] * (num + 2)
    s = [-1] * (num + 2)
    l[1] = 1
    for i in range(2, int(math.sqrt(num + 1)) + 2):
        if l[i] == -1:
            l[i] = i
            for x in range(i * i, num + 1, i):
                if l[x] == -1:
                    l[x] = i
    s[1] = 1
    for i in range(2, num + 1):
        if l[i] == -1:
            l[i] = i
            s[i] = i + 1
        else:
            i1 = i
            s[i] = 1
            while i1 % l[i] == 0:
                i1 //= l[i]
                s[i] = s[i] * l[i] + 1
            s[i] *= s[i1]
    ans = [-1] * (num + 1)
    for i in range(num, 0, -1):
        if s[i] < num:
            ans[s[i]] = i
    for _ in range(int(input())):
        print(ans[int(input())])


# shorttask()

def review():
    for _ in range(int(input())):
        n = int(input())
        ans = 0
        for i in input().split():
            i = int(i)
            if i == 1 or i == 3:
                ans += 1
        print(ans)


# review()

def GCDleng():
    po10 = [0] * 11
    po10[1] = 1
    for i in range(2, 11):
        po10[i] = po10[i - 1] * 10
    for _ in range(int(input())):
        n, n1, res = map(int, input().split())
        print(po10[n], po10[n1] + po10[res])


# GCDleng()


def anothercarddeck():
    n, q = map(int, input().split())
    l = input().split()
    d = {l[i]: i for i in range(n - 1, -1, -1)}
    ans = []
    for i in input().split():
        now = d[i]
        ans.append(now + 1)
        for key in d:
            if d[key] < now:
                d[key] += 1
        d[i] = 0
    print(*ans)


# anothercarddeck()

def mincoststring():
    n, letters = map(int, input().split())
    l = [chr(i + 97) for i in range(letters)]
    ans = []
    real = letters - 1
    if not n:
        print(*ans, sep='')
        return
    if n == 1:
        print(*ans, sep='', end='')
        print(l[1 % (real + 1)])
        return
    while n:
        for i in range(len(l)):
            for i1 in range(i, len(l)):
                if i1 != real:
                    ans.append(l[i1])
                    ans.append(l[i])
                    n -= 2
                else:
                    ans.append(l[i1])
                    n -= 1
                if not n:
                    print(*ans, sep='')
                    return
                if n == 1:
                    print(*ans, sep='', end='')
                    print(l[(i1 + 1) % (real + 1)])
                    return
    print(*ans)


# mincoststring()


def mincost2():
    n, letters = map(int, input().split())
    l = [chr(i + 97) for i in range(letters)]
    comb = []
    if letters == 1 or n == 1:
        print('a' * n)
        return
    for i in range(letters):
        for i1 in range(i, letters):
            comb.append(l[i1] + l[i])
    lc = len(comb)
    while True:
        for i in range(lc):
            if ord(comb[i][0]) - 97 == letters - 1:
                n -= 1
                print(comb[i][0], end='')
            else:
                n -= 2
                print(comb[i], end='')
            if n == 1:
                pos = ord(comb[i][0]) - 97 + 1
                print(l[pos % letters])
                return
            if not n:
                return


# mincost2()
def Tittat():
    for _ in range(int(input())):
        n, k = map(int, input().split())
        l = list(map(int, input().split()))
        for i in range(n):
            if not k:
                break
            while k and l[i]:
                l[i] -= 1
                l[-1] += 1
                k -= 1
        print(*l)


# Tittat()

def xorq2():
    for _ in range(int(input())):
        n = int(input())
        s = 0
        num = -1
        nc = 0
        c = 0
        for i in input().split():
            i = int(i)
            s ^= i
            c += 1
            if num == -1 and s == i:
                num = s
                s = 0
                nc += c
                c = 0
            if num != -1 and (s == num or not s):
                s = 0
                nc += c
                c = 0
        print(['NO', 'YES'][nc == n])


# xorq2()


def xorq2re():
    n = int(input())
    s = input().split()
    xor = 0
    for i in range(n):
        s[i] = int(s[i])
        xor ^= s[i]
    if not xor:
        print("YES")
    else:
        new = 0
        ans = 0
        for i in s:
            new ^= i
            if new == xor:
                new = 0
                ans += 1
        print(["NO", "YES"][ans > 1])


import sys

sys.setrecursionlimit(2300)


def q3partition():
    def partition():
        if tol % 2:
            return 0
        up = tol
        rec = [[False] * (up + 2) for _ in range(n + 1)]
        rec[0][0] = True
        for i in range(1, n + 1):
            v = l[i - 1]
            for j in range(up + 1):
                if rec[i - 1][j]:
                    if v + j <= up:
                        rec[i][j + v] = True
                    rec[i][j] = True

        return rec[n][tol // 2]

    def ints(x):
        nonlocal tol
        nonlocal gcf
        x = int(x)
        tol += x
        gcf = math.gcd(gcf, x) if gcf != float('inf') else x
        return x

    n = int(input())
    tol = 0
    gcf = float('inf')
    l = list(map(ints, input().split()))
    if partition():
        pos = 1
        for i in l:
            if i // gcf % 2:
                print(1)
                print(pos)
                return
            pos += 1
    else:
        print(0)


def permu(n, r):
    return math.factorial(n) // math.factorial(n - r)


def comb(n, r):
    return math.factorial(n) // math.factorial(r) * math.factorial(n - r)


def calc():
    n = int(input())
    ans = permu(n, n)
    for i in range(1, n + 1):
        ans -= comb(n, i)
    print(ans)


# calc()


def order():
    for _ in range(int(input())):
        n = int(input())
        odd = []
        even = []
        for i in input().split():
            i = int(i)
            if i % 2:
                odd.append(i)
            else:
                even.append(i)
        print(*odd + even)


# order()


def TMTdoc():
    n = int(input())
    l = input().rstrip()
    tts = 0
    tms = 0
    for i in l:
        if i == 'T':
            tts += 1
        else:
            tms += 1
    if tms * 2 == tts:
        nowts = 0
        nowms = 0
        for i in l:
            if i == 'T':
                nowts += 1
            else:
                nowms += 1
                if nowts >= nowms and tms - nowms + 1 <= tts - nowts:
                    continue
                return "NO"
    else:
        return "NO"
    return 'YES'


def relayrace():
    def solve(n):
        if n:
            s = -1
        else:
            s = 1
        nowmax = -float('inf')
        nowmin = -nowmax
        ans = 0
        for i, v in sorted(l, key=lambda x: (x[1], s * int(x[0])), reverse=True):
            i = int(i)
            if i > nowmax:
                nowmax = i
            if i < nowmin:
                nowmin = i
            ans += v * (nowmax - nowmin)
        return ans

    n = int(input())
    # l = list(collections.Counter(input().split()).items())
    l = -1
    ans = 0
    for i in sorted(input().split(), key=lambda x: int(x)):
        if l == -1:
            l = int(i)
        else:
            ans += int(i) - l
    return ans


def relayraces():
    n = int(input())
    l = sorted(map(int, input().split()))
    minv = float("INF")
    minpos = 0
    for i in range(len(l)):
        if i > 0 and 0 <= l[i] - l[i - 1] <= minv:
            minv = l[i] - l[i - 1]
            minpos = i
        if i < n - 1 and l[i + 1] - l[i] <= minv:
            minv = l[i + 1] - l[i]
            minpos = i
    lpos = minpos - 1
    rpos = minpos + 1
    ans = 0
    while lpos >= 0 and rpos < n:
        diffl = -(l[lpos] - l[minpos])
        diffr = l[rpos] - l[minpos]
        if diffl < diffr:
            minpos = lpos
            lpos -= 1
            ans += diffl
        else:
            minpos = rpos
            rpos += 1
            ans += diffr
    if lpos < 0:
        m = l[0]
        for i in range(rpos, n):
            ans += l[i] - m
    else:
        h = l[-1]
        for i in range(minpos, -1, -1):
            ans += h - l[i]
    return ans


# sys.setrecursionlimit(2004)


def relayracess():
    def recur(l, r):
        if l == r:
            return 0
        if d[(l, r)] != -1:
            return d[(l, r)]
        ans = nums[r] - nums[l] + min(recur(l + 1, r), recur(l, r - 1))
        d[(l, r)] = ans
        return ans

    d = collections.defaultdict(lambda: -1)
    n = int(input())
    nums = sorted(map(int, input().split()))
    return recur(0, n - 1)


def relayracesss():
    # def recur(l,r):
    #     if l == r:
    #         d[l][r] = 0
    #         return 0
    #     if d[l][r] != -1:
    #         return d[l][r]
    #     ans = nums[r]-nums[l] + min(recur(l+1,r),recur(l,r-1))
    #     d[l][r] = ans
    #     return ans
    # n = int(input())
    # m = n + 20
    # d = [[-1]*m for _ in range(m)]
    n = int(input())
    l = sorted(map(int, input().split()))
    dp = [[0] * n for _ in range(n)]
    for i in range(n - 2, -1, -1):
        for i1 in range(i + 1, n):
            dp[i][i1] = l[i1] - l[i] + min(dp[i + 1][i1], dp[i][i1 - 1])
    return dp[0][n - 1]


def relayracessss():
    n = int(input())
    l = sorted(map(int, input().split()))
    dp = [0] * n
    for le in range(n - 2, -1, -1):
        for ri in range(le + 1, n):
            dp[ri] = l[ri] - l[le] + min(dp[ri], dp[ri - 1])
    return dp[-1]


def binli():
    n = int(input())
    n2 = n * 2
    s = input().rstrip()
    s1 = input().rstrip()
    s2 = input().rstrip()
    posl = [0, 0, 0]
    ans = ''
    while max(posl) < n2:
        l = [[], []]
        l[int(s[posl[0]])].append(0)
        l[int(s1[posl[1]])].append(1)
        l[int(s2[posl[2]])].append(2)
        if len(l[0]) >= 2:
            for i in l[0]:
                posl[i] += 1
            ans += '0'
        else:
            for i in l[1]:
                posl[i] += 1
            ans += '1'
    if posl[0] == n2:
        if posl[1] >= posl[2]:
            ans += s1[posl[1]:]
        else:
            ans += s2[posl[2]:]
    elif posl[1] == n2:
        if posl[0] >= posl[2]:
            ans += s[posl[0]:]
        else:
            ans += s2[posl[2]:]
    else:
        if posl[0] >= posl[1]:
            ans += s[posl[0]:]
        else:
            ans += s1[posl[1]:]
    print(ans)


def almostsort():
    n, k = map(int, input().split())
    ul = 2 ** (n - 1)
    if k > ul:
        return [-1]
    permen = []
    bi = bin(k - 1)[2:]
    if bi == '0':
        return range(1, n + 1)
    pos = n - len(bi)
    ans = list(range(1, pos))
    for i in bi:
        permen.append(pos)
        if not int(i):
            ans += permen[::-1]
            permen = []
        pos += 1
    permen.append(n)
    ans += permen[::-1]
    return ans


def q1_2050():
    for i in range(int(input())):
        s = int(input())
        if s % 2050:
            print(-1)
        else:
            ab = 2050
            while ab <= s:
                ab *= 10
            ab //= 10
            c = 0
            while s and s != 1:
                c += s // ab
                s = s % ab
                while s != 1 and s and s < ab:
                    ab //= 10
            print(c)


def q2jog():
    n, m = map(int, input().split())
    sortbyval = []
    rowsv = [collections.defaultdict(int) for _ in range(n)]
    for row in range(n):
        for i in input().split():
            i = int(i)
            sortbyval.append([i, row])
            rowsv[row][i] += 1
    sortbyval.sort(key=lambda x: x[0])
    larl = []
    for i in range(0, n * m, m):
        larl.append(sortbyval[i:i + m])
    ans = [[0] * m for _ in range(n)]
    person = 0
    for i in larl:
        for v, pos in i:
            ans[pos][person] = v
            rowsv[pos][v] -= 1
            person += 1
            if person == m:
                break
        else:
            continue
        break
    for r in range(n):
        for c in range(m):
            if not ans[r][c]:
                for key in list(rowsv[r].keys()):
                    if not rowsv[r][key]:
                        rowsv[r].pop(key)
                        continue
                    rowsv[r][key] -= 1
                    ans[r][c] = key
                    break
    for i in ans:
        print(*i)


def q3fillomino(n, inp):
    def gorow():
        nonlocal nowp
        nonlocal col
        nonlocal totake
        t = 0
        if nowp and col < n and totake and not l[col][nowp - 1]:
            for back in range(nowp, -1, -1):
                if l[col][back]:
                    nowp += 1
                    col += 1
                    return t
                if not totake:
                    return t
                l[col][back] = i
                totake -= 1
                nowp -= 1
                t = 1
            nowp += 1
            col += 1
        return t

    l = [[0] * i for i in range(1, n + 1)]
    p = 0
    for i in inp:
        totake = int(i)
        nowp = p
        col = p
        while col < n:
            if not totake:
                break
            for _ in range(n - p):
                if not gorow():
                    break
            if not totake or col == n or nowp == n:
                break
            l[col][nowp] = i
            totake -= 1
            col += 1
        p += 1
    for i in l:
        print(*i)


def q3fillominoclear(n, inp):
    l = [[0] * i for i in range(1, n + 1)]
    p = 0
    for i in inp:
        take = int(i) - 1
        l[p][p] = i
        x, y = p, p
        while take:
            if y and not l[x][y - 1]:
                y -= 1
            else:
                x += 1
            l[x][y] = i
            take -= 1
        p += 1
    for i in l:
        print(*i)


def q4explor():
    def gen(r, c):
        res = float('inf')
        if r:
            res = min(res, his[r - 1][c] + 2 * colstep[r - 1][c])
        if r < rows - 1:
            res = min(res, his[r + 1][c] + 2 * colstep[r][c])
        if c:
            res = min(res, his[r][c - 1] + 2 * rowstep[r][c - 1])
        if c < cols - 1:
            res = min(res, his[r][c + 1] + 2 * rowstep[r][c])
        return res

    rows, cols, k = map(int, input().split())
    if k % 2:
        for i in range(rows):
            print(*[-1] * cols)
        return
    rowstep = [list(map(int, input().split())) for _ in range(rows)]
    colstep = [list(map(int, input().split())) for _ in range(rows - 1)]
    his = [[0] * cols for _ in range(rows)]
    for _ in range(k // 2):
        temp = [[gen(r, c) for c in range(cols)] for r in range(rows)]
        his = temp
    for i in his:
        print(*i)


def cvacations():
    def de(v):
        nonlocal last
        if v == 2:
            last = 2
        elif v == 1:
            last = 1

    n = int(input())
    ans = 0
    last = 0  # 0 = none, 1 = gym, 2 = contest
    l = input().split()
    for i1 in range(n):
        i = int(l[i1])
        if not i:
            last = 0
            ans += 1
            continue
        if i == 1:
            if last != 2:
                last = 2
                continue
            ans += 1
            last = 0
        elif i == 2:
            if last != 1:
                last = 1
                continue
            ans += 1
            last = 0
        else:
            if not last:
                if i1 < n - 1:
                    de(int(l[i1 + 1]))
                    if int(l[i1 + 1]) == 3:
                        for pos in range(i1 + 2, n):
                            if l[pos] != 3:
                                r = l[pos]
                                break
                        else:
                            last = 1
                            continue
                        de(r)
                else:
                    break
            elif last == 1:
                last = 2
            elif last == 2:
                last = 1

    return ans


def brackets():
    s = input().rstrip()
    lpos, rpos = 0, len(s) - 1
    ans = []
    while lpos + 1 <= rpos:
        if s[lpos] == '(':
            if s[rpos] == ')':
                ans.append(lpos + 1)
                ans.append(rpos + 1)
                lpos += 1
                rpos -= 1
            else:
                rpos -= 1
        else:
            lpos += 1
    if ans:
        print(1)
        print(len(ans))
        print(*sorted(ans))
    else:
        print(0)


def In():
    return map(int, input().split())


def complibook():
    n, q = In()
    nums = list(In())
    for _ in range(q):
        l, r, x = In()
        num = nums[x - 1]
        les = 0
        for i in range(l - 1, r):
            if nums[i] < num:
                les += 1
        print(["No", "Yes"][les + l - 1 == x - 1])


# complibook()


def bstr():
    for _ in range(int(input())):
        n, k = In()
        now = 1
        times = 2
        while k > now:
            k -= now
            now += 1
            times += 1
        fir = n - times
        sec = n - k
        for i in range(n):
            if i == fir or i == sec:
                print('b', end='')
            else:
                print('a', end='')
        print()


# bstr()


def avgsuper():
    n, k, oper = In()
    l = sorted(In(), reverse=True)
    nowavg = sum(l) / n
    addpos, addnum = 0, 0
    for i in range(oper):
        if n == 1 and addpos != 0:
            break
        new = (nowavg * n - l[n - 1]) / max((n - 1), 1)
        if 1 / n > new - nowavg and addpos < n:
            addnum += 1
            if addnum >= k:
                addpos += 1
                addnum = 0
            nowavg += 1 / n
        else:
            nowavg = new
            n -= 1
    print(nowavg)


# avgsuper()


def avgsuper2():
    n, k, oper = In()
    l = sorted(In(), reverse=True)
    prefix = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix[i] = l[i - 1] + prefix[i - 1]
    prefix.pop(0)
    ans = 0
    for i in range(n - 1, max(-1, n - oper - 2), -1):
        ans = max(ans, (prefix[i] + min(k * (i + 1), oper - (n - i - 1))) / (i + 1))
    return ans


# print(avgsuper2())


def tanna():
    n, k, A, B = int(input()), int(input()), int(input()), int(input())
    if k == 1:
        return (n - 1) * A
    x = n
    ans = 0
    while x != 1:
        if x < k:
            return ans + A * (x - 1)
        if not x % k:
            nexts = x // k
            ans += min(B, A * (x - nexts))
            x = nexts
        else:
            new = (x % k)
            ans += new * A
            x = x - new
    return ans


# print(tanna())


def segsqu():
    square = 1
    num = int(input())
    while num > square * square:
        square += 1
    cols = square
    rows = math.ceil(num / cols)
    print(cols + rows)


# segsqu()

def ParallelUniverses():
    n, k, m, t = In()
    for _ in range(t):
        sta, pos = In()
        if sta:  # insert
            n += 1
            if pos - 1 < k:
                k += 1
        else:
            if pos < k:
                k -= pos
                n -= pos
            else:
                n = pos
        print(n, k)


# ParallelUniverses()


def treasure():
    num = int(input())
    choose = max(list(In()) for _ in range(num))
    ch2 = min(list(In()) for _ in range(num))
    print(choose[0] + ch2[0], choose[1] + ch2[1])


# treasure()

def tradingbus():
    plan, m, cap = In()
    l = []
    for _ in range(plan):
        name = input()
        l.append([list(In()) for _ in range(m)])
    ans = 0
    for i in range(plan):
        fix = l[i]
        for i1 in range(i + 1, plan):
            fix1 = l[i1]
            sellnew = []  # 1
            buynew = []  # buy from planet 2
            for x in range(m):
                fnow = fix[x]
                f1now = fix1[x]
                sellnew.append([max(f1now[1] - fnow[0], 0), fnow[2]])
                buynew.append([max(fnow[1] - f1now[0], 0), f1now[2]])
            sellnew.sort(reverse=True)
            buynew.sort(reverse=True)
            sellc = cap
            buyc = cap
            sa = 0
            ba = 0
            for x in range(m):
                left = sellnew[x][1]
                if left > sellc:
                    sa += sellnew[x][0] * sellc
                    break
                else:
                    sa += sellnew[x][0] * left
                    sellc -= left
            for x in range(m):
                left = buynew[x][1]
                if left > buyc:
                    ba += buynew[x][0] * buyc
                    break
                else:
                    ba += buynew[x][0] * left
                    buyc -= left
            ans = max(ans, max(ba, sa))
    return ans


# print(tradingbus())


def catparty():
    n = int(input())
    colors = [0] * 10
    appeared = 0
    ans = 0
    pos = 1
    for i in In():
        if not colors[i - 1]:
            appeared += 1
        colors[i - 1] += 1
        for x in range(10):
            if colors[x]:
                l1 = colors[:]
                l1[x] -= 1
                l1 = set(l1)
                if 0 not in l1:
                    if len(l1) == 1:
                        ans = pos
                        break
                else:
                    if len(l1) == 2 or len(l1) == 1:
                        ans = pos
                        break
        pos += 1
    return ans


# print(catparty())

def catpartyhard():
    maxn = int(1e5 + 10)
    n = int(input())
    colors = [0] * maxn
    count = [0] * maxn
    pos = 1
    mx = 0
    ans = 0
    for i in input().split():
        i = int(i)
        ok = False
        count[colors[i]] -= 1
        colors[i] += 1
        count[colors[i]] += 1
        mx = max(colors[i], mx)
        if count[1] == pos:
            ok = 1
        elif count[i] == 1:
            ok = 1
        elif count[mx] * mx == pos - 1 and count[1] == 1:
            ok = 1
        elif count[mx - 1] * (mx - 1) == pos - mx and count[mx] == 1:
            ok = 1
        if ok:
            ans = pos
        pos += 1
    return ans


print(catpartyhard())
