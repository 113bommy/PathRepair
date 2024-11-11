n, a, b, c, d = list(map(int, input().split()))
s = input()
if '##' in s[a-1:max(c, d)]:
    out = 'No'
elif c < d:
    out = 'Yes'
elif '...' in s[b-2:d]:
    out = 'Yes'
else:
    out = 'No'
print(out)