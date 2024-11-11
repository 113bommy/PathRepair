from math import ceil


def check(flats_on_level):
    for fl in flats:
        after = ceil(fl[0] / flats_on_level)
        if fl[1] != after:
            return False
    return True


n, m = map(int, input().split())
flats = []
for _ in range(m):
    ki, fi = map(int, input().split())
    flats.append((ki, fi))
answer = -1
cf = -1
if m == 0 and n == 1:
    print(1)
    exit(0)
for i in range(1, 101):
    if check(i):
        if answer == -1:
            answer = i
            cf = i
        else:
            cf == i
if ceil(n / answer) != ceil(n / cf):
    print(-1)
else:
    print(ceil(n / answer))