def main():
    test = int(input())

    for _ in range(test):
        s = input().strip("\r\n")
        n = len(s)
        if n == 1:
            print(1 - int(s[0]))
            continue

        last = s[0]
        ans = 0
        for i in range(1, n):
            if s[i] != last:
                ans += 1 - int(last)
                last = s[i]
            if i == n - 1:
                ans += 1 - int(s[i])
        print(ans)
    return


main()


