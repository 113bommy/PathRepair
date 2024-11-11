import bisect
a,b=map(int,input().split())
c=list(map(int,input().split()))
d=list(map(int,input().split()))
t=0
for i in range(0,a):
    t=t+c[i]
    c[i]=t

k=1
for i in range(0,len(d)):
    r=bisect.bisect_left(c,d[i])
    r=r+1
    if(r>1):
        print(str(r)+" "+str(d[i]-c[r-2]))
    else:
        print(str(r)+" "+str(d[i]))

