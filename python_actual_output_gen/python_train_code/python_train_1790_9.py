a,b=map(int,input().split(" "))
m=min(a,b)
n=max(a,b)
c=0
for i in range(1,m+1):
    num=i%5
    if num==0:
        num=5
    init=abs(5-num)
    ans=(abs(n-init))//5
    if num!=5 and num+init<=n:
        ans+=1
    c+=ans
print(c)
