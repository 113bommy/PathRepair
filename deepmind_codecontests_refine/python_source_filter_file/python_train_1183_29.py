def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    if k < n:
        print(a[k-1], a[k-1])
    else:
        print(-1)


if __name__ == '__main__':
    main()
