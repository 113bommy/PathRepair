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
        # if tol - now == now:
        #     return True
        # return (partition(l[pos] + now, pos + 1) or partition(now, pos + 1)) if pos < n and now <= tol else False
        if tol % 2:
            return 0
        up = tol * 2
        rec = [[False] * (up + 10) for _ in range(n + 1)]
        rec[0][tol] = True
        for i in range(1, n + 1):
            v = l[i - 1]
            for j in range(up + 1):
                if rec[i - 1][j]:
                    if v + j <= up + 3:
                        rec[i][j + v] = True
                    if j >= v:
                        rec[i][j - v] = True
        return rec[n][tol]

    def ints(x):
        nonlocal tol
        x = int(x)
        tol += x
        return x

    n = int(input())
    tol = 0
    l = list(map(ints, input().split()))
    if partition():
        gcf = reduce(lambda x, y: math.gcd(x, y), l)
        pos = 1
        for i in l:
            if i // gcf == 1:
                print(1)
                print(pos)
                return
            pos += 1
    else:
        print(0)


def main():
    # for _ in range(int(input())):
    q3partition()


main()
