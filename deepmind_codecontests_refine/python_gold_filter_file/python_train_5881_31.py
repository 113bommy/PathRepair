n=int(input())
a=input()
b=input()
q=0
d=0
e=0
f=0
g=0
for j in range(0,n):
    if(int(a[j])>int(b[j])):
        if (int(a[j])-int(b[j])<=4) and (int(a[j])-int(b[j])>0):
            g=int(a[j])-int(b[j])+g
        elif (int(a[j])-int(b[j])>4):
            d=(10-int(a[j]))+int(b[j])+d
    else:
        if(int(b[j])-int(a[j])<=4) and (int(b[j])-int(a[j])>0):
            e=int(b[j])-int(a[j])+e
        elif (int(b[j])-int(a[j])>4):
            f=(10-int(b[j])+int(a[j])+f)
q=g+d+e+f
print(q)