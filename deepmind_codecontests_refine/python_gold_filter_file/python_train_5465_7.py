from math import log
T, S, q = map(int, input().split())
print(int(log(T / S - 0.1) / log(q)) + 1 if T > S else 1)