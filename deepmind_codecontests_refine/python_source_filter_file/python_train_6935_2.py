a=list(map(int,input().split()))
if a[0]==12 and (a[1]!=0 or a[2]!=0):
    a[0]=0
if a[3]==12:
    a[3]=0
if a[4]==12:
    a[4]=0
t1=min(a[3],a[4])
t2=max(a[3],a[4])
a[0]+=a[1]/60+a[2]/3600
a[1]=a[1]/5+a[2]/60
a[2]/=5
#print(*a)
a.sort()
ch=0
if a[0]==t1 and a[4]==t2:
    ch=1
for i in range (1,5):
    if a[i]==t2 and a[i-1]==t1:
        ch=1
if ch==1:
    print("YES")
else:
    print("NO")
