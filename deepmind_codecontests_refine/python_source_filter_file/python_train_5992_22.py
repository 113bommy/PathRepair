n = int(input())
arr = list(map(int, input().split()))
used = list(False for x in range(n))

sred = (sum([x for x in arr]) * 2) // 2

for i in range(n):
    for j in range(n):
        if i != j and arr[i] + arr[j] == sred and used[i] != True and used[j] != True:
            print(i + 1, j + 1)
            used[i] = used[j] = True