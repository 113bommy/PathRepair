n=int(input())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
x=0
for i in range(n):
    if a[i]>b[i]:
        x+=a[i]-b[i]
    elif a[i]<b[i]:
        x-=(b[i]-a[i])//2
print(["Yes","No"][x>=0])
