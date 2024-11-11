l=list(map(int,input().split()))
s1=0;s2=0
s1=(l[0]-l[1])+1
t=l[1]-1
k=0
while(t>0):
    s1+=2**k
    k+=1
    t-=1
k=0
x=0
t=l[2]
while(x<l[0] and t>0):
    s2+=2**k
    k+=1
    x+=1
    t-=1
if x<l[0]:
    s2+=(l[0]-x)*2**k
print(s1,end=" ")
print(s2)