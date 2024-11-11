for _ in range(int(input())):
    n = int(input())
    p = 1
    rp = 0
    rem = 0
    dp = []
    while((3/2)*(p**2)+(1/2)*p <= n):
        dp.append(int((3/2)*(p**2)+(1/2)*p))
        if((3/2)*((p+1)**2)+(1/2)*(p+1) == n ):
            rem = n- int((3/2)*((p+1)**2)+(1/2)*(p+1))
            rp = 1
            break
        if((3/2)*((p+1)**2)+(1/2)*(p+1) >= n):
            rem = n- int((3/2)*(p**2)+(1/2)*(p))
            rp = 1
            break
        p+=1
    if(not dp):
        print(0)
    else:
        while(rem >= 2):
            for i in range(len(dp)-1, -1, -1):
                if(rem >= dp[i]):
                    rp += 1
                    rem -= dp[i]
                    break
        print(rp)
