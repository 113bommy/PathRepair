s = input()
ans = ''
for si in s:
    if si == 'B':
        ans = ans[:-1]
    else:
        ans += si
print(ans)