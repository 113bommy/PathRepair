s = list(input().split('/'))
ans = []
for i in s:
    if i != '':
        ans.append(i)
print('/'.join(ans)[1:])