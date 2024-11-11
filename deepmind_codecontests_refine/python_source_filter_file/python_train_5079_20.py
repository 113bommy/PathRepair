def main():
    from bisect import bisect_left as bl
    n, d, a = map(int, input().split())
    xh = [list(map(int, input().split())) for _ in [0]*n]
    xh.sort()
    x_list = [x for x, h in xh]
    ac = [0]*(n+1)
    ans = 0
    temp = 0
    for i in range(n):
        j = xh[i][1]-temp
        if j > 0:
            atk_cnt = (j-1)//a+1
            k = bl(x_list, x_list[i]+2*d)
            ac[i] += a*atk_cnt
            ac[k] -= a*atk_cnt
            ans += atk_cnt
        temp += ac[i]
    print(ans)


main()