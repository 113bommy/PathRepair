for t in range(int(input())):
    n = int(input())
    if n < 4:
        print("-1")
        continue
    pattern = [1, 3, 5, 2, 4]
    ans = [pattern[i % 5] + 5 * (i // 5) for i in range(n // 5 * 5)]
    if n % 5 == 1:
        ans.append(n + 1)
    elif n % 5 == 2:
        ans[-3] = n - 1
        ans += [n, n - 2]
    elif n % 5 == 3:
        ans[-3] = n - 2
        ans += [n, n - 3, n - 1]
    elif n % 5 == 4:
        ans += [n - 1, n - 3, n, n - 2]
    print(*ans)
        