import sys

n, q = map(int, input().split())
s = input()
commands = [line.rstrip().split() for line in sys.stdin]
commands.reverse()

l, r = 0, n - 1
for t, d in commands:
    if s[l] == t and d == 'L':
        l += 1
    elif 0 < l and s[l - 1] == t and d == 'R':
        l -= 1
    elif s[r] == t and d == 'R':
        r -= 1
    elif r < n - 1 and s[r + 1] == t and d == 'L':
        r += 1
    if l > r:
        break

print(r - l + 1)
