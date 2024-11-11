s = set(input())
if len(s) == 4 and (len(s) == 2 and (s == {'S', 'N'} or s == {'E', 'W'})):
    print('Yes')
else:
    print('No')