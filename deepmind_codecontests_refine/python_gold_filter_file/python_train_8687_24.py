n,m,k=map(int,input().split(" "))
a=[]
d=0
for x in range(0,m+1):
    a.append(int(input()))
z='0'*(32-len(str(bin(a[m])[2:])))+str(bin(a[m])[2:])
for x in range(0,m):
    y='0'*(32-len(str(bin(a[x])[2:])))+str(bin(a[x])[2:])
    c=0
    for b in range(0,32):
        if y[b]==z[b]:
            pass
        else:
            c+=1
    if c>k:
        pass
    else:
        d+=1
print(d)