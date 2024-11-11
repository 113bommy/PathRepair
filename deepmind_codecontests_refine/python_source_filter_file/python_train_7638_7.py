a,b,c=map(int,input().split())
l=[]
p=True
for i in range(a):
    l+=list(map(int,input().split()))
l.sort()
s=l[a//2]
cc=0
for i in l:
    k=abs(i-s)
    if(k%c==0):
        cc+=(k//c)
    else:
        print(-1)
        p=False
        break
if p:
    print(cc)
