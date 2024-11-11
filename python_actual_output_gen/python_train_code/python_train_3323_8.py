def solve():
    [n, k] = [int(x) for x in input().split()]
    max_ilands = n * n // 2
    if n % 2 == 1:
        max_ilands += 1

    if k > max_ilands:
        print("NO")
    else:
        print("YES")
        cnt = 0
        ans = [['s'] * n for _ in range(n)]
        for i in range(n):
            if cnt == k:
                break

            j = i % 2
            while j < n:
                ans[i][j] = 'L'
                j += 2
                cnt += 1
                if cnt == k:
                    break
        for i in range(n):
            print("".join(ans[i]))


if __name__ == "__main__":
    solve()




