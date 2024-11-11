n, x, pos = list(map(int, input().split()))

middle = n // 2

left = 0
right = n
larger = []
smaller = []


def fact(p, y=1):
    if p <= 1:
        return y
    else:
        return fact(p - 1, y * p)


while left < right:
    middle = (left + right) // 2
    if middle <= pos:
        if middle < pos:
            smaller.append(middle)
        left = middle + 1
    else:
        larger.append(middle)
        right = middle

# print(larger, smaller)

l = len(larger)
s = len(smaller)
if n - x - l < 0 or x - 1 - s < 0:
    print(0)
else:
    res = 1
    lg = n - x
    for _ in range(l):
        res *= lg
        res %= 10 ** 9 + 7
        lg -= 1
    sm = x - 1
    for _ in range(s):
        res *= sm
        res %= 10 ** 9 + 7
        sm -= 1
    res *= fact(n - l - s - 1)
    res %= (10 ** 9 + 7)
    print(int(res))
