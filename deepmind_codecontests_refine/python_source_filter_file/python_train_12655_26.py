def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    if len(a) == 1:
        print(k - a[0])
        print(k)
        return

        
    ans = 0
    for i in range(1, n):
        s1 = a[i-1] + a[i]
        rem = max(0, k - s1)
        a[i] += rem
        ans += rem


    print(ans)
    print(*a)


if __name__ == "__main__":
    main()

    