"""http://codeforces.com/problemset/problem/499/A"""

parse = lambda st: map(int, st.split())

def solve(x, moments):
    start = 0
    watch = 0
    for l, r in moments:
        watch += (l - start) % x
        r += 1  # watch the whole minute
        watch += r - l
        start = r
    return watch

if __name__ == '__main__':
    n , x = parse(input())
    res = solve(x, [parse(input()) for _ in range(n)])
    print(res)
