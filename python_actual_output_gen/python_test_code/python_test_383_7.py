a=input().split()
b=int(a[0])
c=int(a[1])
d=int(a[2])
e=int(a[3])
if c*d<=e:
    s=b*d
else:
    s=e*(b//c)+d*(b%c)
print(s)
