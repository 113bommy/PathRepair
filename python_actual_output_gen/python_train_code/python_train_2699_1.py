n = int(input())
a=[int(x) for x in input().split()]
maxx=0
c=0
for i in range(n-1):
    if a[i]>=a[i+1]:
        if maxx<c:
            maxx=c
        c=1
    else:
        c+=1
if c>maxx:
    maxx=c
print(maxx)