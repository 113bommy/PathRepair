l1=[]
l2=[]
n=int(input())
for _ in range(n):
    x,y=list(map(int,input().split()))
    l1.append(x)
    l2.append(y)
ans=[0]*n
for i in range(len(l1)):
    for j in range(len(l2)):
        if i==j:
            continue
        if l2[i]!=l1[j]:
            ans[j]=1
print(sum(ans))