import collections


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
    percent = 1-percent*0.01
    for i in range(1,people+1):
        s, s1 = map(int, input().split())
        l.append([i,max(s*t1*percent+s1*t2,s1*t1*percent+s*t2)])
    l.sort(key=lambda x:(x[1]),reverse=True)
    for i in l:
        i[1] = "{:.2f}".format(i[1])
        print(*i)
mushroom()
