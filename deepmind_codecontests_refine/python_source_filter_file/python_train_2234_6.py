n, k = map(int, input().split())
if k > n:
    print(-1)
else:
    ans = n//2
    rem = n%2

    if ans < k:
        ans = k
    elif ans == k and rem != 0:
        ans = k * 2
    elif ans > k:
        if ans % k == 0 and rem == 0:
            ans = ans
        else:
            kk = k
            while ans > k:
                k += kk
            ans = k

    print(ans)



