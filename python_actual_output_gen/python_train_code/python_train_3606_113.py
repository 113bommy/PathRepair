n, a, b, c, d = map(int, input().split())
s = input()
a -= 1
b -= 1
c -= 1
d -= 1
if '##' in s[a:c+1] or "##" in s[b:d+1]:
    print('No')
    exit()

if c > d:
    if '...' in s[b-2:d+1]:
        print('Yes')
    else:
        print('No')
else:
    print('Yes')