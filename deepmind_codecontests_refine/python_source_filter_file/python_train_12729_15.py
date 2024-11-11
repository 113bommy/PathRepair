am=input()
bm=input()
cm=input()
a=[]
b=[]
c=[]
for i in range(len(am)):
    a.append(am[i])
for i in range(len(bm)):
    b.append(bm[i])
for i in range(len(cm)):
    c.append(cm[i])
bo=0
for i in range(len(a)):
    if a[i] in c:
        c.remove(a[i])
    else:
        bo=1
for i in range(len(b)):
    if b[i] in c:
        c.remove(b[i])
    else:
        bo=1
if bo==1 and len(am)+len(bm)==len(cm):
    print('NO')
else:
    print('YES')