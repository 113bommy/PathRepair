n, a, b, c, d = map(int, input().split())
s = set(input())

if '##' in s[a-1:d]:
    print('No')
    exit()

if c < d:
    print('Yes')
    exit()

if '...' in s[b-2:d+1]:
    print('Yes')
else:
    print('No')