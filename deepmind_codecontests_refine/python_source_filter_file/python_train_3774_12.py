"""
wip
link: https://codeforces.com/contest/1360/problem/F
"""
import sys
from collections import Counter
from typing import List


def solve(n: int, m: int, a: List[str]):
    def find(s: str, idx: int, diffs: List[int]):
        if idx == m:
            return s
        c = Counter()
        for i in range(n):
            c[a[i][idx]] += 1

        sorted_by_occurrences = c.most_common()
        most_common_chr, most_common_cnt = sorted_by_occurrences[0]

        for chr, cnt in sorted_by_occurrences:
            if cnt != most_common_cnt:
                break
            for i in range(n):
                if a[i][idx] != chr:
                    diffs[i] += 1
            if all(diffs[i] <= 1 for i in range(n)):
                r = find(s + chr, idx + 1, diffs)
                if r != -1:
                    return r
            for i in range(n):
                if a[i][idx] != chr:
                    diffs[i] -= 1
        return -1

    return find('', 0, [0 for _ in range(n)])


# sys.stdin = open('sample.in')
for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [input() for _ in range(n)]
    r = solve(n, m, a)
    print(r)
