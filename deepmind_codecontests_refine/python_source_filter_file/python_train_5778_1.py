def main():
    d = list(map(int, input().split()))
    res = 0
    for i in range(min(d[0], d[2])):
        res += (i + d[1] - 1) * 2 + 3
    for i in range(min(d[3], d[5])):
        res += (i + d[4] - 1) * 2 + 3
    if d[0] != d[2]:
        res += abs(d[0] - d[2]) * 2 * ( min(d[0], d[2]) * 2 + d[1] )

    print(res)


main()
