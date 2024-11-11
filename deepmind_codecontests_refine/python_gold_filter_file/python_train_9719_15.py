a=[int(x) for x in input().split()]
#d*b=a[0]
#b*c=a[1]
#d*c=a[2]
#b=a[0]/d
#c=a[2]/d
#a[0]*a[2]/d**2=a[1]
d=(a[0]*a[2]/a[1])**0.5
b=a[0]/d
c=a[2]/d
print(int(4*d + 4*b + 4*c))
