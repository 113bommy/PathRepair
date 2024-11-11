from sys import stdin

b, d, s = map(int, stdin.readline().split())


def calculate(last_meal, b, d, s):
    if last_meal == 'b':
        if b > d and b > s:
            return (b - d - 1) + (b - s - 1)
        else:
            new_b = max(b, d) + 1
            return (new_b - d - 1) + (new_b - s - 1) + new_b - b

    elif last_meal == 'd':
        days = max(b, d, s + 1)
        return days - b + days - d + days - 1 - s
    else:
        days = max(b, d, s)
        return days - b + days - d + days - s


print(min(calculate(l, *days) for l in ('b', 'd', 's') for days in ((b, d, s), (d, s, b), (s, b, d))))
