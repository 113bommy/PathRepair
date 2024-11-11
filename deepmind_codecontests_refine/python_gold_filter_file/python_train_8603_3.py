from functools import *
from time import time


def measure_time(fun):
    def wrapper(*args, **kwargs):
        begin = time()
        rv = fun(*args, **kwargs)
        end = time()
        print(end - begin)
        return rv
    return wrapper


def our_cache(func):
    MAX = int(1e6)
    memo = [-1]*(MAX+1)

    @wraps(func)
    def wrapper(arg):
        if memo[arg] == -1:
            memo[arg] = func(arg)
        return memo[arg]
    return wrapper


def main():
    n, k = [int(x) for x in input().split()]
    s = input()
    a = sorted(list(set([x for x in s])))
    t = []
    if k > n:
        t[:] = s
        t += (k-n)*a[0]
    else:
        for i in range(k-1, -1, -1):
            if s[i] == a[-1]:
                continue
            else:
                t[:] = s[:i]
                for j in range(0, len(a)-1):
                    if a[j] == s[i]:
                        t += a[j+1]
                t += (k-i-1)*a[0]
                break
    print("".join(t))


if __name__ == "__main__":
    main()