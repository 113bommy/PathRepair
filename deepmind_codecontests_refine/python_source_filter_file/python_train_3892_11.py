s=input()
d={}
for i in s:
    if i in d:
        d[i]=(d[i]+1)%2
    else:
        d[i]=1
if 1 in d.values():
    s=sum(d.values())-1
else:
    s=sum(d.values())
if s%2==0:
    print("FIRST")
else:
    print("SECOND")
