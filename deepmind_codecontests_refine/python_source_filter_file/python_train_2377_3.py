def main():
    n, a, b = map(int, input().split())
    if b < (n-1)//a+1 or n-a+1 < b:
        print(-1)
        return 0
    for i in range((n-1)//a+1, n-a+2):
        cnt_a = (i-(n-1)//a)
        cnt_b = i-cnt_a-1
        length = n-cnt_a*a-cnt_b
        if length <= a:
            break
    j = n+1
    ans = []
    for i in range(cnt_a):
        j -= a
        ans += list(range(j, j+a))
    if cnt_b >= 0:
        j -= length
        ans += list(range(j, j+length))+list(range(j-1, 0, -1))
    print(*ans)


main()