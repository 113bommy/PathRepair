import math
t=int(input())
ans=[]
for i in range(t):
    a=int(input())
    tmp=0
    if 1<=a<=3:
        tmp=a-1
        ans.append(tmp)
        continue
    tmq=math.floor(math.sqrt(a))
    tsq=tmq**2
    tmp=2*tmq-2
    while tsq<a:
        tsq+=tmq
        tmp+=1
    ans.append(tmp)
print(*ans,sep="\n")