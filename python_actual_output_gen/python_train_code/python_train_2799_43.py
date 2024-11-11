a=input()
a=a.split(' ')
a=[*map(int,a)]
b=a[1]*a[2]
b=b/a[6]
b=b/a[0]
c=a[3]*a[4]
c/=a[0]
d=a[5]
d/=a[0]
e=min(b,c,d)
print(int(e))