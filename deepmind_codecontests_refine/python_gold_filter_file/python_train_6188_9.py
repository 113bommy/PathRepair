def main():
    n, a, b = map(int, input().split())
    ar = list(map(int, input().split()))
    ans = [0] * n
    for i in range(n):
        ans[i] = ((ar[i] * a) % b) // a
    print(*ans)


if __name__ == '__main__':
    main()