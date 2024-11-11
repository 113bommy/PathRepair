n = int(input())
arr = [int(i) for i in input().split()]
stack = []
res = [0 for _ in range(n)]

for i in range(n-1, -1, -1):
    if (stack and stack[-1] > arr[i]):
        res[i] = stack[-1] - arr[i] + 1

    if (not stack):
        stack.append(arr[i])
    elif (stack[-1] < arr[i]):
        stack.append(arr[i])

print(*res)