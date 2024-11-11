import sys

input = sys.stdin.readline

for _ in range(int(input())):
    l, r, m = map(int, input().split())
    for a in range(l, r + 1):
        remainder = m % a # remainder = b - c
        if l <= l + remainder <= r and m >= a:
            ans = [a, l + remainder, l]
        elif l <= l + a - remainder <= r:
            ans = [a, l, l + a - remainder]
    print(*ans)
