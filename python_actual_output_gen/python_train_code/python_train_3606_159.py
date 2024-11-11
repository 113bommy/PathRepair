n, a, b, c, d = map(int, input().split())
s = input()
if s[a-1:c].count('##') == 0 and s[b-1:d].count('##') == 0:
    if c < d:
        print('Yes')
    elif s[b-2:d].count('...') >= 1:
        print('Yes')
    else:
        print('No')
else:
    print('No')