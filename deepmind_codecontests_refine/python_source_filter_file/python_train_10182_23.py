def dfs():
    n = int(input())
    weight = list(map(int, input().split()))
    value = list(map(int, input().split()))
    
    
    def knapsack(n, weight, value):
        dp = [i for i in range(n+1)]
        for i in range(3):
            for j in range(weight[i], n+1):
                dp[j] = max(dp[j], dp[j-weight[i]] + value[i])
        return(dp[-1])
    
    
    new_n=knapsack(n=n, weight=weight, value=value)
    print(knapsack(n=new_n, weight=value, value=weight))

    
dfs()