a=input()
n=len(a)
b=0
c=0
d=[]
e=[]
for i in range(len(a)):
    if a[i]=="a":
        b=b+1
    elif a[i]=="b":
        c=c+1
    d.append(b)
    e.append(c)
f=[]
for i in range(n):
    for j in range(i,n):
        f.append(d[i]+e[j]-e[i]+d[n-1]-d[j])
print(max(f))