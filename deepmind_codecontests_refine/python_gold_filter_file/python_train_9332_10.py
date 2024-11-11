n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
a.sort(key=abs)
b.sort(key=abs)
maxi=-abs(a[-1]*b[-1])-1
I=0
J=0
for i in a:
    for j in b:
        o=max(maxi,i*j)
        if o!=maxi:
            maxi=o
            I=i
            J=j
a.remove(I)
maxi=-abs(a[-1]*b[-1])
for i in a:
    for j in b:
        maxi=max(maxi,i*j)
print(maxi)