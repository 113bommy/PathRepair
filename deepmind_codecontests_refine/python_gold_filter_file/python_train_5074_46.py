a,b=map(int,input().split())
z=list(map(int,input().split()))
z1=[]
s=0
for i in range(a-1):
    if 1&z[i]:s+=1
    else:s-=1
    z1+=[s]
s=[]
for i in range(a-1):
    if z1[i]==0:s+=[abs(z[i]-z[i+1])]
sum=0;i=0;cuts=0
s=sorted(s)
while(i<len(s)):
    if s[i]+sum<=b:sum+=s[i];cuts+=1
    else:break
    i+=1
print(cuts)