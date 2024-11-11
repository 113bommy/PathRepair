n, a, b, c, d = map(int, input().split())
s = input()

if '##' in s[a-1:d]:
    print('No')
    exit()

if c < d:
    print('Yes')
    exit()

if '...' in s[b-1:c]:
    print('Yes')
else:
    print('No')