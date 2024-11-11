import math
st=''
def func(n,k):
    n-=1
    p=pow(2,n)
    if k>p:
        k-=p
    if k&1:
        return 1
    x=math.log(k,2)
    p=(k&(~(k-1)))
    if (x%1)==0:
        return int(x+1)
    p=math.log(p,2)
    return int(p+1)
for _ in range(1):
    n,k=map(int,input().split())
    st+=str(func(n,k))+'\n'
print(st)
