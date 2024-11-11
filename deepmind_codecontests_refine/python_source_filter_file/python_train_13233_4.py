from collections import Counter
n=int(input())
a=list(map(int,input().split()))
b=Counter(a)
s=sum(a)
res=[]

for i in range(n):
    if ((s-a[i])%2==0) and ((s-a[i])//2 in b) and ((s-a[i]//2!=a[i]) or (b[a[i]]>1)):
        res.append(i+1)

print(len(res))
if len(res)!=0:
    print(*res)
