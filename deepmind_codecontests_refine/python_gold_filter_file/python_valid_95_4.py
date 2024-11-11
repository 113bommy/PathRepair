for _ in range(int(input())):
    s, n = map(int, input().split())
    arr = []
    for i in range(1, n):
        m = s - (n - i)
        length = len(str(m))
        val = '1' + '0' * (length - 1)
        arr.append(val)
        s -= int(val)

    arr.append(str(s))

    print(" ".join(arr))