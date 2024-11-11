n=int(input())
a=[i for i in range(1,n+1)]
b=n//4
c=n%4
B=[i for i in range(c+1,4*b+c+1)]
kk=[]
for i in range(1,b+1):
    hhh=4*i-1
    hhhh=4*i-4
    kk.append(B[hhh])
    kk.append(B[hhhh])
if c==0:
    d=0
elif c==1:
    kk.append(1)
    d=1
elif c==2:
    d=1
    kk.append(1)
elif c==3:
    kk.append(2)
    d=2
kk.sort()
k=len(kk)
print(d)
print(k,end=' ')
for i in range(0,k):
    print(kk[i],end=' ')
