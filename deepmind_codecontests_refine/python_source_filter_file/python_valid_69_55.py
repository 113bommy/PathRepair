import collections

t = int(input())

cur = 1
pos = []
while cur <= 10 ** 11:
    pos.append(str(cur))
    cur *= 2

for case in range(t):
    k = input()
    res = float('inf')
    for x in pos:
        # print(x)
        i = 0
        j = 0
        while i < len(x):
            while j < len(k) and i < len(x):
                if x[i] == k[j]:
                    i += 1
                j += 1
            if j == len(k):
                break

        # print(i, j)
        cur = len(x) - i + len(k) - i
        res = min(res, cur)

    print(res)
