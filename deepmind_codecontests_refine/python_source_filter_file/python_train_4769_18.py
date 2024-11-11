# -*- coding: utf-8 -*-
import heapq
import sys
# sys.setrecursionlimit(10**6)
buff_readline = sys.stdin.buffer.readline
readline = sys.stdin.readline

INF = 2**62-1


def read_int():
    return int(buff_readline())


def read_int_n():
    return list(map(int, buff_readline().split()))


def read_float():
    return float(buff_readline())


def read_float_n():
    return list(map(float, buff_readline().split()))


def read_str():
    return readline().strip()


def read_str_n():
    return readline().strip().split()


def error_print(*args):
    print(*args, file=sys.stderr)


def mt(f):
    import time

    def wrap(*args, **kwargs):
        s = time.time()
        ret = f(*args, **kwargs)
        e = time.time()

        error_print(e - s, 'sec')
        return ret

    return wrap


def slv(Q):
    sb = 0

    l = []
    r = []
    sl = 0
    sr = 0

    for q in Q:
        if q[0] == 1:
            _, a, b = q
            heapq.heappush(l, -a)
            sl += a

            if len(l) > len(r) + 1:
                a = -heapq.heappop(l)
                heapq.heappush(r, a)
                sl -= a
                sr += a

            while l and r and -l[0] > r[0]:
                a = -heapq.heappop(l)
                heapq.heappush(r, a)
                sl -= a
                sr += a

                a = -heapq.heappop(r)
                heapq.heappush(l, a)
                sl += a
                sr -= a

            sb += b
        else:
            x = -l[0]
            print(x, abs(sl - len(l)*x) + abs(sr - len(r)*x) + sb)

def main():
    N = read_int()
    Q = [read_int_n() for _ in range(N)]
    slv(Q)


if __name__ == '__main__':
    main()
