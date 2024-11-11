import sys,os,io
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
s = list(input())
a = [0]
for i in range (n):
    if s[i]=='G':
        if a[-1]<0:
            a.append(0)
        a[-1]+=1
    else:
        if a[-1]>0:
            a.append(0)
        a[-1]-=1
ans = max(a)
if len(a)==1 or len(a)==2 or (len(a)==3 and a[0]==-1):
    print(max(ans,0))
else:
    nm = 0
    for i in range (1,len(a)-1):
        if a[i]==-1:
            nm = max(nm,a[i-1]+a[i+1])
    if len(a)==3 or len(a)==4 or (len(a)==5 and a[0]<0):
        print(max(ans+1, nm))
    else:
        print(max(ans+1,nm+1))