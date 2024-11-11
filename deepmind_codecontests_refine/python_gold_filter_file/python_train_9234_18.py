import math
n,vb,vw=map(int,input().split())
list1=list(map(int,input().split()))
xi,yi=map(int,input().split())
ll=[]
s1=0
s2=0
for i in range(1,n):
    s1=(list1[i])/vb
    s2=math.sqrt(((xi-list1[i])**2) + ((yi)**2))/vw
    ll.append(s2+s1)

m=min(ll)
l2=[]
for i in range(len(ll)):
    if(ll[i]==m):
        l2.append(i+2)
mm=100000000000
ind=0
for i in range(len(l2)):
    if(abs(list1[l2[i]-1]-xi)<mm):
        mm=abs(list1[l2[i]-1]-xi)
        ind=l2[i]
print(ind)
               