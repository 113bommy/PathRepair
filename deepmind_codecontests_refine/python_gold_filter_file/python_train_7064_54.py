s = list(input())
ans = ''
for i in s:
    if i in 'C':
        ans += i
    elif i in 'F':
        ans += i
print('Yes' if 'CF' in ans else 'No')