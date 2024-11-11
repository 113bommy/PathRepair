n = int(input())
inp = list(map(int, input().split()))

input_parse = []
dp = []
for i in input_parse:
    if len(input_parse) == 0:
        input_parse.append(i)
    elif i <= input_parse[-1]:
        dp.append(input_parse)
        input_parse = [i]
    else:
        input_parse.append(i)

dp.append(input_parse)
optimum = 0
if len(dp) != 1:
    for i in range(len(dp) - 1):
        if len(dp[i]) == 1 or len(dp[i+1]) == 1:
            curr_opt = len(dp[i]) + len(dp[i+1])
        elif dp[i + 1][0] - dp[i][-2] > 1 or  dp[i + 1][1] - dp[i][-1] > 1:
            curr_opt= len(dp[i]) + len(dp[i+1])
        else:
            curr_opt=max(len(dp[i]), len(dp[i+1])) + 1
        if curr_opt > optimum:
            optimum = curr_opt
    print(optimum)
else:
    print(len(dp[0]))
