import math

def main():
    n, d = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]

    if d!=5 and d!=0:
        a = list(filter(lambda x: x%5!=0 ,a))

    if d&1:
        a = list(filter(lambda x: x%2, a))

    n = len(a)

    dp = [[-1 for _ in range(10)] for _ in range(n + 1)]
    path = [[(0, 0, 0) for _ in range(10)] for _ in range(n + 1)]
    
    dp[0][1] = 0
    
    for i in range(n):
        for j in range(10):
            val = dp[i][j] + math.log(a[i])
            if dp[i + 1][(j * a[i])%10] <= val:
                dp[i + 1][(j * a[i])%10] = val
                path[i + 1][(j * a[i])%10] = (i, j, 1)
            
            val = dp[i][j]
            if dp[i + 1][j] <= val:
                dp[i + 1][j] = val
                path[i + 1][j] = (i, j , 0)
    
    ans = []
    test, pd = 1, d
    while n > 0 :
        if path[n][d][2] == 1:
            ans.append(a[n - 1])
            test = (test * a[n - 1])%10
        
        n,d = path[n][d][:2]
    
    if test == pd and len(ans) > 0:
        print(len(ans))
        print(' '.join(map(str, ans)))
    else:
        print(-1)


if __name__=='__main__':
    main()
