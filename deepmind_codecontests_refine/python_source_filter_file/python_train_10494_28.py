n, a, b, c, d = map(int, input().split())
s = input()

ans = 'Yes'
if s[a-1:c].find('##') > -1:
    ans = 'No'
elif s[b-1:d].find('##') > -1:
    ans = 'No'
else:
    if d < c:
        if s[b-1:d].find('...') == -1:
            ans = 'No'

print(ans)
