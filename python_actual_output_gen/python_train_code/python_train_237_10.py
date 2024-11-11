t=int(input(""))
d=list(map(int,input("").split(" ")))
f=int(input(""))
a=list(map(int,input("").split(" ")))
v=[]
for i in d:
    l=[]
    for j in a:
        if j%i==0:
            l.append(j//i)
        else:
            pass
    if len(l)>=1:
        v.append(max(l))
print(v)
g=max(v)
s=0
for  o in range(len(v)):
    if g==v[o]:
        s+=1
print(s)