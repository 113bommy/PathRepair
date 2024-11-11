import itertools
import sys
from collections import defaultdict, Counter
from math import sqrt

input = sys.stdin.readline


############ ---- Input Functions ---- ############
def inp():
    return (int(input()))


def inlt():
    return (list(map(int, input().split())))


def insr():
    s = input()
    return (list(s[:len(s) - 1]))


def invr():
    return (map(int, input().split()))


def s(d):
    dis = 1 + 4 * 2 * 3 * d
    ds = sqrt(dis)
    return (-1 + ds) / 6


def main():
    d = inp()
    for i in range(d):
        d1 = inp()
        v = inlt()
        dc = dict(Counter(v))
        mx = 0
        for j in range(2*d1):
            m = 0
            for k,vv in dc.items():
                if k == j-k:
                    m+=vv
                else:
                    vv2 = dc.get(j - k)
                    if vv2:
                        m += min(vv2, vv)
            mx = max(m, mx)
        print(mx//2)





if __name__ == "__main__":
    # sys.setrecursionlimit(10 ** 6)
    # threading.stack_size(10 ** 8)
    # t = threading.Thread(target=main)
    # t.start()
    # t.join()
    main()
