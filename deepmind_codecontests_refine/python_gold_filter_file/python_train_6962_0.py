import functools


@functools.lru_cache(maxsize=None)
def rec(i):
    if i <= 0:
        return i == 0
    return rec(i-1) + rec(i-2) + rec(i-3)

while True:
    N = int(input())
    if not N:
        break
    print(((rec(N)-1)//10)//365+1)