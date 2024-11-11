n, a, b, c, d = map(int, input().split())
s = input()

if '##' in s[a-1:c] or '##' in s[b-1:d]:
    print('No')
else:
    if d<c and '...' not in s[b-1:d]:
        print('No')
    else:
        print('Yes')

