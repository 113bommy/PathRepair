def check(sum, n, x, s):
    if sum - n * x >= s:
        return True
    else:
        return False


def main():
    n, s = map(int, input().split())
    sum = 0
    minval = 99999999
    a = input().split()
    for i in range(n):
        sum += int(a[i])
        minval = min(minval, int(a[i]))
    if sum < s:
        print(-1)
    else:
        l = 0
        r = minval
        ans = 0
        while l <= r:
            m = (l + r) // 2
            if check(sum, n, m, s):
                l = m + 1
                ans = max(ans, m)
            else:
                r = m - 1
        print(ans)


main()