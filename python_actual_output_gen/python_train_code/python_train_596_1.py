import sys

k = int(input())
d = [0]
for i in range(1, 12):
    d.append((10 ** i - 10 ** (i - 1)) * i + d[i - 1])
print(d)
for i in range(1, len(d)):
    if k <= d[i]:
        f = d[i - 1]
        f1 = 10 ** (i - 1)
        # print(i, f)
        # print(str(((k - f - 1) // i) + f1))
        print(str(((k - f - 1) // i) + f1)[(k - f - 1) % i])
        sys.exit()
