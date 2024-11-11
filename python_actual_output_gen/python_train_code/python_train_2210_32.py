c=[]
a=input()
list=a.split()
b=input()
list=b.split()
for i in range(len(a)):
    if a[i]==b[i]:
        c.append(0)
    else:
        c.append(1)
print(c,sep='')