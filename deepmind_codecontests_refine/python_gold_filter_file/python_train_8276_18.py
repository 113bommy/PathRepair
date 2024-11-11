a=input().split(":")
m=int(input())
h=0
m=m+int(a[1])
if m>=60:
    h=m//60
    m=m%60
a[1]=m
a[0]=(int(a[0])+h)%24
print("{:02d}:{:02d}".format(a[0],a[1]))