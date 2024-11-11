tst = int(input())


for t in range(tst):
    n = int(input())
    s = input()
    fst = s.find("0")
    lst = n - s[::-1].find("0") - 1

    if fst == -1:
        k = n // 2
        print(1, 2 * k, 1, k)
        continue

    if lst >= n // 2:
        print(1, lst + 1, 1, lst)
    elif fst < n // 2:
        print(fst + 1, n, fst + 2, n)