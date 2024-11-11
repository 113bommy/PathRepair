import bisect
def cal(n):
    x=str(n)
    res=0
    if len(x)==1:
        return n
    for i in range(1,len(x)):
        res=res+9*(10**(max(0,i-2)))
    a=[]
    for i in range(1,10):
        s=str(i)+'0'*(max(0,len(x)-2))+str(i)
        a.append(int(s))
    j=bisect.bisect_right(a,n)
    res=res+(j-1)*(10**(max(0,len(x)-2)))
    if j<len(a) and x[0]==str(a[j])[0]:
        res=res+10**(max(0,len(x)-2))
    else:
        for i in range(1,len(x)-1):
            res=res+int(x[i])*(10**(len(x)-2-i))
        if len(x)>=3:
            res=res+1
        if int(x[0])>int(x[-1]):
            res=res-1
    return res
l,r=list(map(int,input().split()))
ans=cal(r)-cal(l)
if str(l)[0]==str(l)[-1]:
    ans=ans+1
print(ans)