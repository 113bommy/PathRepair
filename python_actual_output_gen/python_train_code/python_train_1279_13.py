s=input()
a="abcdefghijklmnopqrstuwxyz"
x=[i for i in s]
y=[]
for i in x:
    if i in y:
        continue
    else:
        y.append(i)
l=len(y)
j="".join(y)
if a[:l]==j:
    print("YES")
else:
    print("NO")