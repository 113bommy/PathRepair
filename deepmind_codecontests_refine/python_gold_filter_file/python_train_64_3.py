n=int(input())
a=input().split()
d=0
for i in range(len(a)):
    a[i]=int(a[i])
    if a[i]<500001:
        if a[i]-1 > d:
            d=a[i]-1
    else:
        if 10**6-a[i] > d:
            d=10**6-a[i]
print(d)
