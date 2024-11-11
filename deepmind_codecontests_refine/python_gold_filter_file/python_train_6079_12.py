from itertools import accumulate
s = input()
n = int(input())
req = [map(int, input().split()) for _ in range(n)]

a = [0] + list(accumulate([1 if s[i] == s[i + 1] else 0 for i in range(len(s) - 1)] + [0]))
for l, r in req:
    print(a[r - 1] - a[l - 1])