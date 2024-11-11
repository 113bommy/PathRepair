a=input()
b=input()
a1=int(a);
b1=int(b);
c1=a1+b1;
x=""
y=""
for i in a:
    if(i=="0"):
        continue
    else:
        x=x+i
for i in b:
    if(i=="0"):
        continue
    else:
        y=y+i

x1=int(x)
y1=int(y)
c=x1+y1;
d=str(c1)
res=""
for i in d:
    if(i=="0"):
        continue
    else:
        res=res+i
c=str(c)
#r=int(res)
print(c+" "+res);
if(c==res):
    print("YES")
else:
    print("NO")