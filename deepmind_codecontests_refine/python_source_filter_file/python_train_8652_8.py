n,k=map(int,input().split())
s=list(map(int,input().split()))
from collections import Counter
c=Counter(s)

z=dict()
def f(x):
    global n,k,c,z
    if x>n:return False
    if x==0:return True
    ret=0
    z=dict()
    for i in c:
        ret+=c[i]//x
        z[i]=c[i]//x
    #print(x,ret)
    return ret>=k

#l:True,r:False
l,r=0,10**6
while l+1<r:
    y=l+(r-l)//2
    if f(y):
        l=y
    else:
        r=y
f(l)
#print(z)
ans=[]
for i in z:
    for j in range(z[i]):
        ans.append(str(i))
print(" ".join(ans))