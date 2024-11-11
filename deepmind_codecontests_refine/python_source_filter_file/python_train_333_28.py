n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))
sums, suf, q1 = [0]*n, [n]*n, n
for q in range(n-2, -1, -1):
    sums[q] = sums[q + 1]
    if a[q] != a[q1-1]:
        sums[q] += (n-q1)*(a[q1-1]-a[q])+(q1-q-1)*(a[q1-1]-a[q]-1)
        q1 = q + 1
    suf[q] = q1
ans, sum1, q1 = sums[0]+k-suf[0] if suf[0] < k else 0, 0, 0
for q in range(1, n):
    if a[q] != a[q1 + 1]:
        sum1 += q1*(a[q]-a[q1+1])+(q-q1-1)*(a[q]-a[q1+1]-1)
        q1 = q - 1
    if suf[q]-q1 >= k:
        ans = 0
        break
    if k <= suf[q]:
        ans = min(ans, sum1+k-suf[q]+q1+1)
    if k < n-q1:
        ans = min(ans, sums[q]+k-suf[q]+q1+1)
    ans = min(ans, sum1+sums[q]+k-suf[q]+q1+1)
print(ans)
