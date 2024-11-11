 n, k = map(int, input().split( ))

a = list(map(int, input().split( )))

dp = [0]*(k+1)

for i in range(k+1):
    win = 0
    for j in a:
        if i>=j and dp[i-j] == 0:
            win = 1
            break
    dp[i] = win
#print(*dp)            
if dp[k] == 1:
    print("First")
else:
    print("Second")