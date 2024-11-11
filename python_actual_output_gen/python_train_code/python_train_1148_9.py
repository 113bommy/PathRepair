t = int(input())
for i in range(t):
    s = input().split(" ")
    n = int(s[0])
    k = int(s[1])

    s = input().split(" ")
    arr = []
    for l in s:
        arr.append(int(l))

    answer = arr[0]
    for j in range(1, k - 1):
        dist = (arr[j] - arr[j-1])//2 + 1
        answer = max(answer, dist)
    answer = max(answer, n - arr[k - 1] + 1)
    print(answer)