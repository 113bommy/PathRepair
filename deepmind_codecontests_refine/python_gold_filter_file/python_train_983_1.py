from collections import defaultdict as dc
def serch(a,b,x,y):
        for i in range(1,n):
                if (b[a[i]-x-y]):
                        return a[i]-y
                if b[a[i]-(y-x)] and a[i]+x<=l:
                        return a[i]+x
                if b[a[i]+(y-x)] and a[i]-x>=0:
                        return a[i]-x
        return 0
                
n,l,x,y=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
b=dc(int)
b=dc(lambda :0,b)
k1=0
k2=0
for i in range(n):
        b[a[i]]=1
        if b[a[i]-x]==1:
                k1=1
        if b[a[i]-y]==1:
                k2=1
if k1==1 and k2==1:
        print(0)
elif k1==0 and k2==0:
        z=serch(a,b,x,y)
        if z!=0:
                print(1)
                print(z)
        else:
                print(2)
                print(x,y)
elif k1==0:
        print(1)
        print(x)
else:
        print(1)
        print(y)



                
