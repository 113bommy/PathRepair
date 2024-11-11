a = "AHIMOoTUVvWwXxYbdpq"
b = "AHIMOoTUVvWwXxYdbqp"
s = input()
l, r = 0, len(s)-1
f=True
while l<=r:
    if s[l] in a:
        i1=a.index(s[l])
    else:
        i1=-1
    if s[r] in b:
        i2=b.index(s[r])
    else:
        i2=-1
    if i1==-1:
        f=False
        break
    if i1!=i2:
        f=False
        break
    l+=1
    r-=1
if f:
    print("TAK")    
else:
    print("NIE")
