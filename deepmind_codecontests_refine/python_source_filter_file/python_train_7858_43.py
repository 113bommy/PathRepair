n = int(input())
a = list(map(int, input().split()))
k = 1
ans = -1
for i in range(1,n):
    if a[i] > a[i-1]:
        k += 1
    else:
        ans = max(ans,k)
        k = 1
print(max(ans,k))