a, b, c = map(int, input().split())

if (4*a*b < c-a-b) and c-a-b >= 0:
    print('Yes')
else:
    print('No')