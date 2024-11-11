def solve(n, x, d):
    b = [d[0]]
    tmp = d[0]*(d[0]+1)//2
    c = [tmp]
    ans = 0
    length = len(d)
    n *= 2
    for i in range(1, n):
        b.append(b[i-1]+d[i % length])
        tmp = d[i % length]*(d[i % length]+1)//2
        c.append(tmp+c[i-1])
    for i in range(n):
        l = 0
        r = i
        key = b[r]-x
        if key < 0:
            continue
        while l < r:
            mid = (l+r)//2
            tmp = b[i]-b[mid]
            if tmp > x:
                l = mid+1
            else:
                r = mid
        cnts = c[i]-c[r-1]
        diff = b[i]-b[r-1]
        days = diff-x
        cnts -= days*(days+1)//2
        ans = max(cnts, ans)
    return ans


def main():
    n, x = list(map(int, input().split()))
    d = list(map(int, input().split()))
    ans = solve(n, x, d)
    print(ans)


if __name__ == "__main__":
    main()
