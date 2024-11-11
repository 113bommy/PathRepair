def dislike_three(k):
    i, n, l = 0, 0, 0
    while n != k:
        i += 1
        if i % 3 and str(i)[-1] != "3":
            n += 1
            l = i
    return l

t = int(input())

for _ in range(t):
    k = int(input())
    print(dislike_three(k))
