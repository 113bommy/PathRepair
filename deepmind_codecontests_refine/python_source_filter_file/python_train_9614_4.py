import bisect

n = int(input())
a = [int(x) for x in input().split()]
p = [int(x) for x in input().split()]
b = [0, 0, 0, 0, 0]
s = 0
for i in a:
    s += i
    k = bisect.bisect_right(p, s)
    while k != 0:
        if (k == 5) or (p[k] > s):
            k -= 1
        b[k] += s // p[k]
        s %= p[k]
        k = bisect.bisect_left(p, s)
print(' '.join(list(map(str, b))))
print(s)
