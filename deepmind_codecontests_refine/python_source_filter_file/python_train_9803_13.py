n = int(input())
arr = [i for i in range(n+1)]
cnt = 1
for i in range(2,n+1):
    if arr[i] < cnt:
        continue

    else:
        j = i
        while j <= n:
            arr[j] = cnt
            j += 2

        cnt += 1

print(*arr[2:])