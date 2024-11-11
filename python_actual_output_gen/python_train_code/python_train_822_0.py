k = int(input())
arr = list(map(int,input().strip().split()))[:k]

if sum(arr)%3 == 0:
    sums = sum(arr)//3
else:
    print(-1)
    exit(0)


sum2 = sums*2
count = 0;ans = 0;c1 = 0
for i in range(k-1):
    count += arr[i]
    if count == sum2:
        ans += c1
    if count == sums:
        c1 += 1


print(ans)
