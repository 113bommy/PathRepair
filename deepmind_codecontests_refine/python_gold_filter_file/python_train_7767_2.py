n = int(input())
m = n
arr = input()
arr = list(map(int, arr.split(' ')))
dp = list('0'*n)
maxi = 0
mini = 0
while m:
    m = m - 1
    if arr[m] + mini > maxi:
        dp[m] = arr[m] + mini
        mini = maxi
        maxi = dp[m]
    elif arr[m] + mini <= maxi:
        dp[m] = maxi
        mini = arr[m] + mini
print(mini, ' ', maxi)




