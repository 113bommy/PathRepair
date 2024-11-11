import sys

n, a, b = tuple([int(x) for x in sys.stdin.readline().split()])
values = sorted([int(x) for x in sys.stdin.readline().split()])

result = abs(values[a] - values[b])
print(result)
