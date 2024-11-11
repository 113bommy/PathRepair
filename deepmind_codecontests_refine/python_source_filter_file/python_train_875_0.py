a=input().split()
#a=list(map(int,a))
a=[int(i) for i in a]
print(int(min(a[0],a[1],a[2]/2,a[3]/8,a[4]/4)))