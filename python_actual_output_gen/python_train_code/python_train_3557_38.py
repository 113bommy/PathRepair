"""http://codeforces.com/problemset/problem/276/A"""

def solve(k, l):
    res = -1 * 1e5
    for i in l:
        i = list(i)
        joy = i[0] if i[1] <= k else i[0] - i[1] - k
        res = max(res, joy)
    return res

n, k = map(int, input().split())
l = [map(int, input().split()) for _ in range(n)]
print(solve(k, l))