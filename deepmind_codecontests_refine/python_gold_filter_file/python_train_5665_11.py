n=int(input())
L=[]
ol=0
ou=0
d=0
for i in range(n):
    l=list(map(int,input().split()))
    L.append(l)
    e=0
    o=0
    if(l[0]%2!=0):
        ol=ol+1
        e=1
    if(l[1]%2!=0):
        ou=ou+1
        o=1
    if(e!=o):
        d=1
if(ol%2!=0 and ou%2!=0 and d==1):
    print(1)
elif(ol%2==0 and ou%2==0):
    print(0)
else:
    print(-1)