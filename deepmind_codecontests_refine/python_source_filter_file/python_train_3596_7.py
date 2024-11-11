import sys


def inputs():
    inp = sys.stdin.readline()
    return inp


n, x = map(int, inputs().split())
distress = 0
for _ in range(n):
    need, cream = map(str, inputs().split())
    if need == '+':
        x += int(cream)
    elif need == '-':
        if (x - int(cream)) >= 0:
            x -= int(cream)
        else:
            distress += 1

print(n, x)
