l=[0,0,0,0,0,0,0,0,0,0]
kitten=0
x=input()
x=x.split()
a=""
w=int(x[0])
y=int(x[1])
for i in range(w):
    a+=input()
for i in range(w):
    for j in range(y):
        if a[i*w+j]=='Y':
            l[j]+=1
c=0
for i in range(y):
    if l[i]>=int(x[2]):
        c+=1
print(c)
