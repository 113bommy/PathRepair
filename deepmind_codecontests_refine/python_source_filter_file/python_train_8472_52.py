
import functools
import logging
import os
import sys
import time
from typing import List

logger = logging.getLogger()
reader = sys.stdin

# Need to define DEBUGGING variable when run locally
is_judge = os.getenv("DEBUGGING") is None


def timeit(func):
    @functools.wraps(func)
    def timed(*args, **kwargs):
        if is_judge:
            rv = func(*args, **kwargs)
        else:
            ts = time.time()
            rv = func(*args, **kwargs)
            te = time.time()

            logger.debug("performance %r %2.2fms", func.__name__, (te - ts) * 1000)
        return rv
    return timed


def read_ints():
    return [int(v) for v in reader.readline().strip().split(" ")]

# ----------------------
# -     /SOLUTION      -
# ----------------------


def main():
    n, k = read_ints()
    # 1, 3, 5, ... n
    # 2, 4, 6, ... n
    if n % 2 == 0:
        if k < n//2:
            res = (k - 1) * 2 + 1
        else:
            res = (k - n//2) * 2
    else:
        if k <= n//2 + 1:
            res = (k - 1) * 2 + 1
        else:
            res = (k - (n//2 + 1)) * 2
    print(res)


# ----------------------
# -     \SOLUTION      -
# ----------------------


def setup():
    global logger, reader

    if is_judge:
        logger.setLevel(logging.WARNING)
    else:
        # Format logger
        handler = logging.StreamHandler(sys.stdout)
        handler.setLevel(logging.DEBUG)
        formatter = logging.Formatter("{asctime}s - {message}", style='{')
        handler.setFormatter(formatter)

        logger.addHandler(handler)
        logger.setLevel(logging.DEBUG)

        # Stdin from file
        reader = open("input.txt")


if __name__ == '__main__':
    setup()
    try:
        main()
    except KeyboardInterrupt:
        logger.debug("KeyboardInterrupt")
    except IOError as e:
        logger.error(f"I/O error({e.errno}): {e.strerror}")

