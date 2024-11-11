n, k = map(int, input().split())
arr = list(map(int, input().split()))
el = []
count = 0
ans = 0
ex = []

for i in range(len(arr)):
    if arr[i] % k == 0:
        count += 1
    else:
        el.append(arr[i] % k)
i = 1
while i*2 <= k:
    if k-i == i:
        ans += el.count(i)
    else:
        ans += 2*(min(el.count(i), el.count(k-i)))
    i += 1
ans += count//2*2
print(ans)
