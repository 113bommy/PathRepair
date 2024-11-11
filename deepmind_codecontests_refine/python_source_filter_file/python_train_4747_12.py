import math 
def res():
    d=0
    s=0
    n,k=input().split(); n=int(n); k=int(k);N=n
    if(n==1 and k==1):
        print(1)
        return
    for i in range(1,int(math.sqrt(int(N)))+1):
        if(n%i==0):
            d1=i
            d2=n/i
            s1=k*(k-1)*d1/2
            s2=k*(k-1)*d2/2
            if(n-s1>(k-1)*d1 and d<d1):
                d=d1
                s=s1
            if(n-s2>(k-1)*d2 and d<d2):
                d=d2
                s=s2
    if(d==0):
        print(-1)
        return
    for i in range(1,k):
        print(d*i,end=" ")
    print(int(n-s))
res()