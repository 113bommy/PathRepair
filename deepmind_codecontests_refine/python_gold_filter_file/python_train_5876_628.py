
a=input()
b=input()
c=[]
for i in a:
    if i=="s":
        c.append("s")
    else:
        c.append(i)
#print(c,b)
c=c[::-1]
#print(c)
c="".join(c)
#print(c)
if c==b:
    print("YES")
else:
    print("NO")