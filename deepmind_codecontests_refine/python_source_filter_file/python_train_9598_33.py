def main():
    (n, a, b) = map(int, input().split(' '))

    ret = 0
    for i in range(a, n):
        for j in range(n, -1, -1):
            if i + j != n - 1:
                continue
            ret += 1
    print(ret)

main()
