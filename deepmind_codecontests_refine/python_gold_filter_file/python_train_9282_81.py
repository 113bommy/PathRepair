a, b, c = [int(x) for x in input().split()]
if a > min(b, c):
    print('No')
else:
    print('Yes')