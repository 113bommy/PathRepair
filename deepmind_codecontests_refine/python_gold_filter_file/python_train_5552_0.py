n = int(input())
arr = []
for i in range(n):
    a, b = map(int, input().split())
    arr.append([b, a])
arr.sort()
counter = 1
answer = 0
i = -1
while counter > 0 and i != -n-1:
    answer += arr[i][1]
    counter += arr[i][0] - 1
    i -= 1
print(answer)