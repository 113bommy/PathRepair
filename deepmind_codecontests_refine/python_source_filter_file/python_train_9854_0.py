from functools import *
from time import time
from heapq import *


def measure_time(fun):
    def wrapper(*args, **kwargs):
        begin = time()
        rv = fun(*args, **kwargs)
        end = time()
        print(end - begin)
        return rv
    return wrapper


def our_cache(func):
    memo = [-1]*(max+1)

    @wraps(func)
    def wrapper(arg):
        if memo[arg] == -1:
            memo[arg] = func(arg)
        return memo[arg]
    return wrapper


def main():
    n, c = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]

    if c >= n:
        print(sum(a))
        exit(0)

    b = n * [0]
    s = 0
    h = []
    for i in range(n):
        s = s + a[i] if i <= c-1 else s + a[i] - a[i-c]
        heappush(h, (a[i], i))
        if i <= c-2:
            b[i] = s
        else:
            while i-h[0][1] >= c:
                heappop(h)
            v1 = b[i-c] + s - h[0][0]
            v2 = a[i] + b[i-1]
            b[i] = min(v1, v2)

    print(b[-1])


if __name__ == "__main__":
    main()