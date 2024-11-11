import sys

l = [True] * 100000
for i in range(2, 100000):
    if (l[i - 1]):
        for j in range(i ** 2 - 1, 100000, i):
            l[j] = False
for n in sys.stdin:
    print(l[1:int(n)].count(True))