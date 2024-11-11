n,w=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
a.sort()
print(min(min(a[n]/2,a[1])*(n*3),w))