n, k = map(int, input().split())
a = list(map(int, input().split()))

dp = [False]*(k+1)
for i in range(1, k):
    flag = False
    for ai in a:
        if i-ai >= 0 and  not dp[i-ai]:
            flag = True
            break
    dp[i] = flag

if dp[-1]:
    print("First")
else:
    print("Second")