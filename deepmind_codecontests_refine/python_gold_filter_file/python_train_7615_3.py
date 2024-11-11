# Lang: pypy3.6-v7.1.0-win32\pypy3.exe
# Problem Name: FromZeroToHero
# Problem Serial No: 1175
# Problem Type: A
# Problem Url: https://codeforces.com/contest/1175/problem/A 
# Solution Generated at: 2019-06-06 00:51:34.101810 UTC


def r(a, x):
    a, b = divmod(a, x)
    count = 0
    while a >= x:
        count += b + 1  # count steps on each divs
        a, b = divmod(a, x)
    return count, a, b


tc = int(input())
for _ in range(tc):
    a, x = map(int, input().split())
    c, d, e = r(a, x)
    print(c + d + e + (0 if c == 0 and d == 0 else 1))

# Accepted
