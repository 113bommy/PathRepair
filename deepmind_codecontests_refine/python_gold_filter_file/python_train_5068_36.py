n,b=map(int,input().split())
l=list(map(int,input().split()))
oc=0
ec=0
tmp=[]
for i in range(0,n-1):
    if l[i]&1==1:
        oc+=1 
    else:
        ec+=1 
    if ec==oc:
        tmp.append(abs(l[i+1]-l[i]))
tmp.sort()
c=0
for i in range(len(tmp)):
    if b>=tmp[i]:
        c+=1
        b-=tmp[i]
    else:
        break
print(c)
    