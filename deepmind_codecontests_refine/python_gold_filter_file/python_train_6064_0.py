n=int(input(""))
n in range (1,10**5)
m=input("")
l=m.split(" ")
l=list(map(int,l))
l.sort()
a=min(l)
b=max(l)
b1=l.index(b)
if b>1 and a>1:
    a=a-1
    l[b1]=1;
elif b>1 and a==1:
    l[b1]=a;
if b==1 and a==1:
    l[b1]=b+1;
l.sort()
print(" ".join(map(str,l)))
