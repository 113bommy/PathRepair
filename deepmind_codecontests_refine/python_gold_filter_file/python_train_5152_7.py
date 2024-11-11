a=input()
b=int(input())
c=[]
d=0
f=[]

for i in range(b):
    e=input()
    c.append(e)

for i in c:
    if(a in i[0:len(a)]):
        d+=1
        f.append(i)
    else:
        pass


if(d>=1):
    print(min(f))
else:
    print(a)