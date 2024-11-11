s = input()
cnt = [0 for _ in range(26)]
for i in s:
    cnt[ord(i) - ord('a')] += 1
ans = max(cnt)
cntt = [[0 for _ in range(26)] for _ in range(26)]
for i in s:
    cnt[ord(i) - ord('a')] -= 1
    for j in range(26):
        cntt[ord(i) - ord('a')][j] += cnt[j]
print(max(ans, max([max(x) for x in cntt])))