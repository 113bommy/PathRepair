a=[]
c=0
for x in range(0,5):
    n1=list(map(int,input().split(" ")))
    a.append(n1)
for y,z in enumerate(a):
    if 1 in z:
        k=y
        j=z.index(1)
if k!=3:
    c=c+abs(2-k)
if j!=3:
    c=c+abs(2-j)
print(c)