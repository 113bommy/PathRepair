import re
import functools

N = int(input())
MOD = 10 ** 9 + 7


@functools.lru_cache(maxsize=2**24)
def dfs(cur, last3):
    if cur == N:
        return 1
    ret = 0
    for c in 'ACGT':
        if not re.match('.AGC|.ACG|.GAC|A.GC|AG.C', last3 + c):
            ret += dfs(cur + 1, last3[1:] + c)
    return ret % MOD


print(dfs(0, 'TTT'))