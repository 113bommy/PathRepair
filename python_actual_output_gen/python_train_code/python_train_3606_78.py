n,a,b,c,d = map(int,input().split())
s = input()


if('##' in s[a:d]):
    print('No')
    exit()
if(c < d):
    print('Yes')
else:
    if('...' in s[b:d-1]):
        print('Yes')
    else:
        print('No')
