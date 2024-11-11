a=[int(i) for i in input().split()]
a.sort()
print('Yes' if a[0]+a[1]==a[2] else 'No')
