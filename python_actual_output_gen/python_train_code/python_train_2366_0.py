k=int(input())
a=[0]*k
b=[0]*k
i=0
while i<k:
    l=list(map(str,input().split()))
    a[i]=l[0]
    b[i]=int(l[3])+int(l[4])+int(l[5])+int(l[6])+int(l[7])+int(l[1])-int(l[2])
    i=i+1
print(a[b.index(max(b))])
