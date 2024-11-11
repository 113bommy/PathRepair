n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
b=list(map(int,input().split()))
st=0
end=10**9
ans=-1
while st<=end:
    mid=(st+end)//2
    e=0
    s=-k
    for i in range(n):
        t=b[i]-a[i]*mid
        if t<0:
            s=s-t
    if s==0:
        ans=mid
        break
        end=mid-1
    elif s>0:
        end=mid-1
    else:
        st=mid+1
if ans==-1:
    print(end)
else:
    print(ans)