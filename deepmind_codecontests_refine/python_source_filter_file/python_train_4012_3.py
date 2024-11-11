a=[int(i) for i in input().split(" ")]
a1=a[0]
a2=a[1]
k=0
while a1>0 and a2>0:
    if a1<=a2:
        a1=a1+1
        a2=a2-2
    else:
        a2=a2+1
        a1=a1-2
    k=k+1
if a[0]==1 or a[1]==1:
    k=0
print(k)
