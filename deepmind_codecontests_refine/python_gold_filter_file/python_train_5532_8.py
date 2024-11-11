a=input()
b=len(a)
c=0
for i in range(b):
    if a[i]=="4" or a[i]=="7":
        c+=1
c=str(c)
b=len(c)
d=0
for i in range(b):
    if c[i]=="4" or c[i]=="7":
        d+=1
if d==b:
    print("YES")
else:
    print("NO")