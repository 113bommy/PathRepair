a=[int(i) for i in input().split(" ")]
present=a[0]
number=a[1]
l=[0 for i in range(present-1)]
while number:
    a=[int(i) for i in input().split(" ")]
    if(a[0]==2):
        l[a[1]-1]=2
    else:
        l[a[1]-1]=2
        l[a[2]-1]=1
    number-=1
maxi = l.count(0)
mini=0
c=l
for i in range(present-2):
    if c[i]==0 and c[i+1]==0:
        mini+=1
        c[i]=2
        c[i+1]=1
mini+=c.count(0)
print(mini,maxi)