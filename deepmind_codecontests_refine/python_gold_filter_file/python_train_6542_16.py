n,p = map(int,input().split())
a = list(map(lambda x:int(x)%2,input().split()))
cnt0 = a.count(0)
cnt1 = n-cnt0
if cnt0==n and p==0:
    print(2**n)
elif cnt0==n and p==1:
    print(0)
else:
    print(2**(n-1))