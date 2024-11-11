n = int(input())
arr = list(map(int, input().split()))
start = 0
maximum = arr[0]
minimum = arr[0]
longest = 0

for i in range(1, n):
    if abs(arr[i] - arr[i - 1]) <= 1:
        maximum = max(maximum, arr[i])
        minimum = min(minimum, arr[i])
        if abs(maximum - minimum) <= 1:
            if i == n - 1:
                temp = i - start + 1
                longest = max(longest, temp)
        else:
            temp = i - start
            longest = max(longest, temp)
            for j in range(i, start - 1, -1):
                if abs(arr[i] - arr[j]) > 1:
                    start = j + 1
                    break

            maximum = max(arr[i], arr[start])
            minimum = min(arr[i], arr[start])

    else:
        temp = i - start
        longest = max(longest, temp)
        start = i
        maximum = arr[i]
        minimum = arr[i]

print(longest)