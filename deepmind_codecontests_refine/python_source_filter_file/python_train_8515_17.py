n,k=map(int,input().split())
s=input()+"d"
d=[]
r=s[0]
c=0
for i in range(n+1):
    if r==s[i]:
        c+=1
    else:
        d.append(c)
        r=s[i]
        c=1
if s[0]=="0":
        d=[0]+d
if s[-2]=="0":
    d+=[0]
if len(d)<=2*k+1:
    print(n)
else:
    l=sum(d[:2*k+1])
    p=sum(d[:2*k+1])
    for i in range(len(d)-2*k-3):
        p=p-d[2*i]-d[2*i+1]+d[2*i+2*k+1]+d[2*i+2*k+2]
        l=max(l,p)
    print(l)