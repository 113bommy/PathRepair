n, a, b, c, d = map(int, input().split())
s = input()
if '##' in s[a:d+1]:
    print('No')
elif c < d or '...' in s[b:c+1]:
    print('Yes')
else:
    print('No')