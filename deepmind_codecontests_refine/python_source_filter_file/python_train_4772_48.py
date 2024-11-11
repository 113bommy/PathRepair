s = sorted(input())
t = sorted(input())

t = t[::-1]

if s <= t:
    print('Yes')
else:
    print('No')
