num_input = input()
num_input = num_input.split(" ")
n = int(num_input[0])
k = int(num_input[1])

arr = input()
arr = arr.split(" ")

for i in range(0, len(arr)):
    arr[i] = int(arr[i])

dp = [arr[0]]

for i in range(1, len(arr)):
    if arr[i] + dp[i - 1] >= 5:
        dp.append(arr[i])
    else:
        dp.append(k - dp[i - 1])

count = 0

for i in range(0, len(arr)):
    count += abs(arr[i] - dp[i])

for i in range(0, len(arr)):
    dp[i] = str(dp[i])

res = " ".join(dp)
print(count)
print(res)

