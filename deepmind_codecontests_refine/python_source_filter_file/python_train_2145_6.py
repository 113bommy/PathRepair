l1=input()
l1=l1.split()
n=int(l1[0])
k=int(l1[1])
a=input()
a=a.split()
b=input()
b=b.split()
for i in range(n):
    a[i]=int(a[i])
for i in range(k):
    b[i]=int(b[i])
def Increasing(a):
    fb='NO'
    fp="NO"
    for i in range(len(a)-1):
        if a[i]>a[i+1]:
            fb='YES'
        if a[i]<a[i+1]:
            fp="YES"
    f=[fb,fp]
    if "NO" in f:
        return "NO"
    return "YES"
def Check1(a,b):
    f='NO'
    t=a.count(0)
    if t>2:
        return "YES"
    if t<2:
        i=a.index(0)
        a[i]=b[0]
        return Increasing(a)
    if t==2:
        aa=a.copy()
        i=aa.index(0)
        aa[i]=b[0]
        i=aa.index(0)
        aa[i]=b[1]
        ########
        i=a.index(0)
        a[i]=b[1]
        i=a.index(0)
        a[i]=b[0]
        f=Increasing(a),Increasing(aa)
        if 'YES' in f:
            return "YES"
        return "NO"
print(Check1(a,b))
                    
    
