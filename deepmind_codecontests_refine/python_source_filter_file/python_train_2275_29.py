input()
a = list(map(int, input().split()))
if 1 & len([i for i in a if i&1]):
    print('No')
else:
    print('Yes')
