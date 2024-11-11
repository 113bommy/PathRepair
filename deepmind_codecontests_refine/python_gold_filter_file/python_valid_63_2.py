def gcd(a,b):
    return b if  a == 0 else gcd(b % a, a)
def lcm(a,b):
    return (a / gcd(a,b))* b
mini=100000
tests=1#int(input())
# arr=list(map(int,input().split()))
mod=10**9+7
def getParent(d,i):
    if(d[i]==-1):
        return i
    else:
        return getParent(d,d[i])

while(tests):
    tests-=1
    # n=int(input())
    a={}
    b={}
    arr=list(map(int,input().split()))
    n,m1,m2=arr[0],arr[1],arr[2]
    for i in range(n):
        a[i+1]=-1
        b[i+1]=-1
    while(m1):
        m1-=1
        arr=list(map(int,input().split()))
        a1,b1=arr[0],arr[1]
        a[getParent(a,max(a1,b1))]=getParent(a,min(a1,b1))
    while(m2):
        m2-=1
        arr=list(map(int,input().split()))
        a1,b1=arr[0],arr[1]
        b[getParent(b,max(a1,b1))]=getParent(b,min(a1,b1))
    # print(a,b)
    ct=0
    ans=[]
    for i in range(1,n+1):
        for j in range(i+1,n+1):
            if(i!=j and (a[i]==-1 or b[i]==-1)):
                pia=getParent(a, i)
                pja=getParent(a, j)
                pib=getParent(b, i)
                pjb=getParent(b, j)
                if((pia!=pja or (pia==-1 and pja==-1)) and (pib!=pjb or (pib==-1 and pjb==-1))):
                    a[getParent(a,max(i,j))]=getParent(a,min(i,j))
                    b[getParent(b,max(i,j))]=getParent(b,min(i,j))
                    ans.append([i,j])
    print(len(ans))
    for i in ans:
        print(i[0],i[1])  