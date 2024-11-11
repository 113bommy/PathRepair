a=input()
c=1
k=1
for i in range(len(a)):
    if a[i]!='A' and a[i]!='E' and a[i]!='I' and a[i]!='O' and a[i]!= 'U' and a[i]!='Y':
        c+=1
    else:
        if k<c:
            k=c
            c=1
        else:
            c=1
print(k)


