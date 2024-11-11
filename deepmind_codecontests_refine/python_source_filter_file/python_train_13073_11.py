n=int(input())
o=0
y=[]
q=input()
for i in range(len(q)):
    y.append(int(q[i]))
a=y[:]
y.sort()
v=input()
x=[]
for i in range(len(v)):
    x.append(int(v[i]))
b=x[:]
x.sort()
for i in range(len(x)):
    for k in range(len(y)):
        if x[i]>y[k] and y[k]!=-1:
            y[k]=-1
            o=o+1
            break
z=0
a.sort()
b.sort()
for i in range(len(a)):
    for k in range(len(b)):
        if a[i]<=b[k] and a[i]!=-1:
            a[i]=-1
            z=z+1
            break
print(n-z)
print(o)