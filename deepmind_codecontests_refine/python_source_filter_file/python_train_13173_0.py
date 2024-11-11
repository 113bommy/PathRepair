st=[int(i) for i in input().split(" ")]
a=st[0]
b=st[1]
ar=[]
k=0
kmax=-1
for i in range(b):
    n=str(input())
    if n=="1"*a:
        ar.append(0)
    else:
        ar.append(1)
for i in range(len(ar)):
    if ar[i]==1:
        k+=1
        if k>kmax:
            kmax=k
    else:
        k=0
print(kmax)
