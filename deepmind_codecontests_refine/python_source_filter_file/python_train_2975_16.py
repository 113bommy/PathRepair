l=[list(map(int,input().split())) for i in range(3)]
print(3)
for i in range(3):
    a=l[i]
    b=l[(i+1)%3]
    c=l[i-1]
    ab=[b[0]-a[0],b[1]-a[1]]
    bc=[c[0]-b[0],c[1]-b[1]]
    print(a[0]+ab[0]+bc[0],a[1]+ab[1]+bc[1])