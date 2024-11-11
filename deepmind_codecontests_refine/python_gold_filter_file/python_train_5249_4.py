i=lambda:map(int,input().split())
a,b,k=i()
d=list(i())
d.sort()
for i in d:
    if i%2:b-=1
    elif b>k:b-=1
    else:k-=1
print((min(0,b)+min(0,k))*-1)