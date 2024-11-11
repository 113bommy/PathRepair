n, d = map(int, input().split())
ans = -1
curr = 0
for i in range(d):
    s = input()
    if '0' in s:
        curr += 1
        ans = max(ans, curr)
    else:
        curr = 0
print(ans)
    