n = int(input())
arr = [-1 for i in range(n+1)]
cnt = 1
for i in range(2,n+1):
    if arr[i] != -1:
        continue

    else:
        j = i
        while j <= n:
            arr[j] = cnt
            j += i

        cnt += 1

print(*arr[2:])