n, a, b, c, d = map(int, input().split())
s = str(input())
if '##' in s[a:c] or '##' in s[b:d]:
    print('No')
else:
    if c < d:
        print('Yes')
    else:
        if '...' in s[b - 1:d + 2]:
            print('Yes')
        else:
            print('No')
