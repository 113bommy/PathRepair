n, k = map(int, input().split()) 
cnt = [0]*k
for i in map(int, input().split()):
    cnt[i % k] += 1
ans = 2 * (cnt[0] // 2)
for i in range(1, k):
    if 2*i >= k:
        break;
    else:
        ans += 2 * min(cnt[i], cnt[k - i])
if k % 2 == 0:
    ans += 2 * (cnt[k//2] // 2)
print(ans)