import math

t = int(input())

for k in range(t):
    n = int(input())

    d = [-1]

    for i in range(2, int(n ** 0.5 + 2)):
        if not n % i:
            d.append(i)

    if len(d) == 1:
        print(1, n)
        continue

    for i in range(1, len(d)):
        d.append(int(n / d[i]))

    d.append(int(n / d[-1]))
    d = list(set(d))
    d.remove(-1)
    d.sort()

    # print(d)

    print(d[-1], n - d[-1])
