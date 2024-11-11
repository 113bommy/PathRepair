import sys
input = sys.stdin.readline
from pprint import pprint

INF = 1 << 63

issqrt = set()
for i in range(0, 1000000):
    issqrt.add(str(2 ** i))
    if (2**i) > 10**24:
        break
def do():
    n = int(input())
    s = str(n)
    sl = len(s)
    res = 10 ** 9
    if s in issqrt:
        print(0)
        return
    for candidate in issqrt:
        found = 0
        for i in range(len(s)):
            if s[i] == candidate[found]:
                found += 1
            if found == len(candidate): break
        need = 0
        need += sl - found # need erase
        need += len(candidate) - found # must add
        res = min(res, need)

    print(res)

q = int(input())
for _ in range(q):
    do()


