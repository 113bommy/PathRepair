def main():
    n = int(input())
    a = list(map(int, input().split()))
    if not a[n - 1]:
        print(*[i for i in range(1, n + 2)])
        return
    if a[0]:
        print(n + 1, *[i for i in range(1, n + 1)])
        return
    for j in range(1, n):
        if a[j - 1] == 0 and a[j] == 1:
            print(*[i for i in range(1, j + 1)], n + 1, *[i for i in range(j + 1, n + 1)])
            return
    print(-1)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        main()
