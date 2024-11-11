s = input()
a = ["0","1"]
i = 0
l = len(s)
while i<l-1:
    b = []
    for j in a:
        b.append("0"+j)
    for j in a:
        b.append("1"+j)
    a=b
    i+=1
import math
q = 0
r = 10**18
a = a[1:]
for i in a:
    k = ""
    for j in range(l):
        if i[j]=="1":
            k+=s[j]
    z = 0
    x = len(k)
    while z<x:
        if k[z]=="0":
            z+=1
        else:
            break
    k = k[z:]
    if k=="":
        continue
    p = int(k)
    if p!=0:
        if math.ceil(p**(0.5))==math.floor(p**(0.5)):
            q+=1
            r = min(r,i.count("0")+z)
if q==0:
    print(-1)
else:
    print(r)
