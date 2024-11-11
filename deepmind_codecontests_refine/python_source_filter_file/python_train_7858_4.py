n = int(input())
a=[int(x) for x in input().split()]
maxx=0
c=1
for i in range(1, n-1):
    if a[i]>a[i+1]:
        if maxx<c:
            maxx=c
        c=1
    else:
        c+=1
if c>maxx:
    maxx=c
print(maxx)