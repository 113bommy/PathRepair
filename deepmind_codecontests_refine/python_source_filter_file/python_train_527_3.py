n,k=map(int, input().split())
s=[c for c in input()]
s.sort()
ans = 0
last = -1
cnt = 0
if k <n:
    for i in range(n):
        if last == -1 or ord(s[i]) - ord(last) > 1:
            cnt += 1
            ans += ord(s[i]) - ord('a') + 1
            last = s[i]
        if cnt == k:
            break
else:
    ans = -1
if cnt < k:
    ans = -1
print(ans)
