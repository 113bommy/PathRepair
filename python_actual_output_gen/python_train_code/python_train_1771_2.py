n, m = map(int, input().split())

arr = list(map(int, input().split()))

res = [0]

for i in range(1, n):
    s = arr[i]
    temp = sorted(arr[:i])
    print(temp)
    cnt = 0
    for j in temp:
        if(s > m):
            break
        cnt += 1
        s += j
    print(cnt, arr[i], s)
    if(s <= m):
        res.append(0)
    else:
        res.append(i-cnt+1)
print(res)