n = int(input())
arr = list(map(int, input().split()))
ans = True

for i in range(n):
    if i + 1 !=arr[i]:
        for j in range(arr[i],n):
            if j + 1 != arr[j]:
                ans = False
                break
        for j in range(i, arr[i]):
            if arr[i]-j+1 != arr[j]:
                ans = False
                break
        if ans:
            print(i+1, arr[i])
            exit(0)
        break

print(0, 0)



