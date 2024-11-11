n=int(input())
a=[int(i) for i in input().split()]
if n==1:
    print(sum(a))
    exit()
a.sort()
zhecijiaji=sum(a)
he=zhecijiaji*2
for i in range(n-2):
        zhecijiaji=zhecijiaji-a[i]
        he=he+zhecijiaji
print(he)
