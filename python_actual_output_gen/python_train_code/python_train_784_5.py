a=int(input())
b=int(input())
c=a+b
a=list(str(a))
b=list(str(b))
c=list(str(c))
an=[];bn=[];cn=[]
for i in a:
    if a!="0":
        an.append(i)
for i in b:
    if b!="0":
        bn.append(i)
for i in c:
    if c!="0":
        cn.append(i)
if int("".join(a))+int("".join(b))==int("".join(c)):
    print("YES")
else:
    print("NO")
