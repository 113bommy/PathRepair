import sys,io,os
try:Z=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
except:Z=lambda:sys.stdin.readline().encode()
X=lambda x:print(x)or quit()
n=int(Z());a,b,c=sorted(map(int,Z().split()));t=map(int,Z().split());d=[0]*7
B=[a,b]+sorted([a+b,c])+[a+c,b+c,a+b+c]
for i in t:
    for v in range(7):
        if i<=B[v]:d[v]+=1;break
    else:X(-1)
t=sum(d[3:]);d[6]=0;d[0]=max(0,d[0]-d[5]);d[5]=0
if d[1]>=d[4]:d[1]-=d[4]
else:d[0]=max(0,d[0]+d[1]-d[4]);d[1]=0
d[4]=0
if a+b<=c:
    if d[1]>=d[3]:d[1]-=d[3];d[0]=max(0,d[0]-d[3])
    else:
        e=d[3]-d[1];d[0]=max(0,d[0]-d[1]);d[1]=0
        if e>(d[0]+1)//2:e-=(d[0]+1)//2;d[2]=max(0,d[2]-e);d[0]=0
        else:d[0]=max(0,d[0]-2*e)
else:
    if d[2]>=d[3]:d[2]-=d[3]
    else:
        e=d[3]-d[2];d[2]=0
        if d[1]>=e:d[1]-=e
        else:e-=d[1];d[1]=0;d[0]=max(0,d[1]-e)
d[3]=0
if d[1]>=d[2]:d[1]-=d[2];d[0]=max(0,d[0]-d[2]);t+=d[2];d[2]=0
else:
    e=d[2]-d[1];d[0]=max(0,d[0]-d[1]);t+=d[1];d[2]-=d[1];d[1]=0
    v=(d[0]+1)//2
    if e>v:e-=v;t+=v;d[2]-=v;d[0]=0;X(t+(d[2]+1)//2)
    else:d[0]=max(0,d[0]-2*e);d[2]-=e
m=d[1]//2
if m>=d[0]:X(t+m+(d[1]%2))
else:X(t+m+(d[0]-m+(d[1]%2)+2)//3)