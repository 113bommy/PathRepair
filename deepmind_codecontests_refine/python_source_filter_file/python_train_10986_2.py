n = int(input())
a = list(map(int, input().split()))
ans = []

for i in range(n):
    count = 0
    j = i
    while j < n-1 and a[j+1] <= a[j]:
        j += 1
        count += 1
    j = i
    while j > 0 and a[j-1] <= a[j]:
        j -= 1
        count += 1
    ans.append(count)

print(max(ans))
