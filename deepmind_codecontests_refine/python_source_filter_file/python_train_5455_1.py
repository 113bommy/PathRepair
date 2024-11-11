import sys
from array import array  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


n, m, s = map(int, input().split())
if n <= s or m <= s:
    print(n * m)
    exit()

cnt_x = ((n - 1) // s + 1) * ((n - 1) % s + 1)
cnt_y = ((m - 1) // s + 1) * ((m - 1) % s + 1)
print(cnt_x * cnt_y)
