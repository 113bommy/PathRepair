def binomialCoef(n, k): 
    C = [[0 for x in range(k+1)] for x in range(n+1)] 
  
    # Calculate value of Binomial Coefficient in bottom up manner 
    for i in range(n+1): 
        for j in range(min(i, k)+1): 
            # Base Cases 
            if j == 0 or j == i: 
                C[i][j] = 1
  
            # Calculate value using previously stored values 
            else: 
                C[i][j] = C[i-1][j-1] + C[i-1][j] 
  
    return C[n][k] 
            
n, m = map(int, input().split())
M = 1e9 + 7

print(int(int(binomialCoef(n + 2*m - 1, 2*m)) % M))