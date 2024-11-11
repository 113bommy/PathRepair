b=int(input())
c=0
d=0
a=[int(i) for i in input().split()]
for i in range(1,b+1):
    if a[i-1]<0 and d<=0:
        c+=1
    elif a[-1]<0 and d>0:
        d-=c
    else:
        d+=a[i-1]
print(c)
