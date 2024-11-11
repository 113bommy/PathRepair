import math
n=int(input())
# n>=3
a=list(map(int,input().split()))
a.sort()
su=sum(a)-n
if n>=30:
    print(su)
    exit(0)
def comp(po,lis):
    polis=[po**i for i in range(len(lis))]
    su=0
    for i in range(len(lis)):
        su+=abs(lis[i]-polis[i])
    return su
maxval=math.ceil(max(a)**(1/(n-1)))
# print(maxval)
pows=[maxval-1,maxval,maxval+1]
ans=su
for p in pows:
    ans=min(ans,comp(p,a))
print(ans)