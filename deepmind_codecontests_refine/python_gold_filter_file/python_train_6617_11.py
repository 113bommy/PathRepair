n1, n2, n = sorted([int(s) for s in input().split(' ')])
a = list(sorted([-int(s) for s in input().split(' ')]))
print('{:.30}'.format(-sum(a[0:n1])/n1 - sum(a[n1:n1+n2])/n2))