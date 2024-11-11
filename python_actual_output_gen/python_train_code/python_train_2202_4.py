if __name__ == '__main__':
    n = int(input())
    a = [0] + [int(i) for i in input().split()] + [0]
    mx = 10*6 + 1

    for i in range(n + 1):
        mx = min(mx, max(a[i], a[i + 1]))

    print(mx, a)