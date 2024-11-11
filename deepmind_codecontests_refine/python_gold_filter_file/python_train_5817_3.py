s = input()

ans = ''
for i in s:
    if i == 'B':
        ans = ans[0:-1]
    else:
        ans += i
print(ans)