"""http://codeforces.com/problemset/problem/447/B"""

def solve(st, k, w):
    _max = max(w)
    vals = [w[ord(c) - ord('a')] for c in st]
    idx = 0
    while idx < len(st) and vals[idx] < _max:
        idx += 1
    vals = vals[:idx+1] + [_max] * k + vals[idx+1:]
    return sum([(i + 1) * x for i, x in enumerate(vals)])

if __name__ == '__main__':
    res = solve(input(), int(input()), list(map(int, input().split())))
    print(res)
