n, k = map(int, input().split())
a = [0] + list(map(int, input().split()))

cnt = {0:1}

ans = 0

for i in range(1, n+1):
    left = i - k + 1
    if left >= 0:
        ldif = (a[left] - left) % k
        if ldif < 0: ldif += k
        cnt[ldif] -= 1
    
    a[i] += a[i-1]
    dif = (a[i] - i) % k
    if dif < 0: dif += k
    if dif not in cnt:
        cnt[dif] = 0
        
    ans += cnt[dif]
    cnt[dif] += 1

print(ans)