def main(n, a):
    def s(n, a, i):
        a[0] += i
        amt = 0
        for j in range(1, n):
            while a[j] >= a[0] and amt <= i:
                a[j] -= 1
                amt += 1
        return a[1:]
    a[1:] = reversed(sorted(a[1:]))
    for i in range(1, 100):
        x = list(filter(lambda x: x >= a[0] + i, s(n, list(a), i)))
        if len(x) == 0:
            return i
    return -1



print(main(int(input()), list(map(int, input().split(' ')))))
