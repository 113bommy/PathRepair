s = input()
ans = ''

for _ in s:
    if _ == 'B':
        ans = ans[:-1]
    else:
        ans += _
print(ans)