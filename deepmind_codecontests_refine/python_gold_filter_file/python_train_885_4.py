from collections import defaultdict
from pprint import pprint
import sys
import time
from collections import Counter
from functools import total_ordering, lru_cache
from random import randint
from sys import stderr
from typing import Union

INF = 10 ** 18 + 3
EPS = 1e-10
MAX_CACHE = 10 ** 9


# Decorators
def time_it(function, output=stderr):
    def wrapped(*args, **kwargs):
        start = time.time()
        res = function(*args, **kwargs)
        elapsed_time = time.time() - start
        print('"%s" took %f ms' % (function.__name__, elapsed_time * 1000),
              file=output)
        return res

    return wrapped


@time_it
def main():
    n, a, b, c = map(int, (input() for _ in range(4)))

    or_n = n
    opt1 = n // a
    opt2 = max(0, n - c) // (b - c)

    n -= opt2 * (b - c)
    opt2 += n // a

    n = or_n % a
    opt1 += max(0, n - c) // (b - c)

    res = max(opt1, opt2)
    print(res)


def set_input(file):
    global input
    input = lambda: file.readline().strip()


def set_output(file):
    global print
    local_print = print

    def print(*args, **kwargs):
        kwargs["file"] = kwargs.get("file", file)
        return local_print(*args, **kwargs)


if __name__ == '__main__':
    set_input(open("input.txt", "r") if "MINE" in sys.argv else sys.stdin)
    set_output(sys.stdout)
    main()
