n = int(input())
arr = [int(p) for p in input().split()]
prev = -1
val = 0
ans = [0]*n
cnt = 0
neg = []
for i in range(len(arr)):
    if arr[i] < 0:
        neg.append(i)
for i in range(len(arr)):
    if arr[i] > 0:
        ans[i] = val
    elif arr[i] < 0:
        val = i-prev
        cnt += 1
        if cnt > 2:
            val += ans[neg[cnt-2]]
        ans[i] = val
        prev = i
print(sum(ans), n*(n+1)//2 - sum(ans))