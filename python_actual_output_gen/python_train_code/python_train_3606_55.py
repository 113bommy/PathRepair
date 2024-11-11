[n, a, b, c, d] = [int(i) for i in input().split()]
s = input()

if ('##' in s[b:d]) and ('##' in s[a:c]):
    print('No')
elif c > d:
    if '...' in s[b - 1:d]:
        print('Yes')
    else:
        print('No') 
else:
    print('Yes')
