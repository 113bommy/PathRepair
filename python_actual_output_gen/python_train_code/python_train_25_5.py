n=int(input())
a=input().split()
d=0
for i in range(len(a)):
    a[i]=int(a[i])
    if a[i]<50001:
        if a[i]-1 > d:
            d=a[i]-1
    else:
        if 50001-a[i] > d:
            d=50001-a[i]
print(d)
