a,b=input().split()
while(len(a)!=len(b)):
    if(len(a)<len(b)):
        a="0"+a
    if(len(b)<len(a)):
        b="0"+b
c=""
f=1
d=0
for i in range(len(a)):
    e=int(b[i])+int(a[len(a)-i-1])
    d=d+(e*f)
    f=f*10
print(d)