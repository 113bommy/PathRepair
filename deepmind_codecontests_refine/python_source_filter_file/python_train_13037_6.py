def solve(arr,n,ans):
    dp = [[0 for i in range(27)] for j in range(n)]
    for i in range(n):
        dp[i][arr[i]] += 1
        if i > 0:
            for j in range(27):
                dp[i][j] += dp[i-1][j]

    max_val = 1
    for i in range(n):
        left = dp[i][:]
        for j in range(i+1,n):
            total = 0
            counts = dp[j-1][:]
            for k in range(27):
                counts[k] -= dp[i][k]

            total += max(counts)
            right = dp[-1][:]
            for k in range(27):
                right[k] -= dp[j-1][k]

            max_curr = 0
            for k in range(27):
                max_curr = max(max_curr,left[k]+right[k])
                
            total += max_curr

            max_val = max(max_val,total)

        max_val = max(max_val,max(left))

    ans.append(max_val)

def main():
    t = int(input())
    ans = []
    for i in range(t):
        n = int(input())
        arr = list(map(int,input().split()))
        solve(arr,n,ans)

    for i in ans:
        print(i)


main()
