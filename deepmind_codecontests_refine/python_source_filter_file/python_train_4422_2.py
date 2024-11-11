n=int(input())
a=list(map(int,input().split()))
if a==sorted(a):
    print(0)
    exit()
ans=0
ans2=[[] for i in range(n)]
for i in range(n):
    j=i
    for z in range(i,n):
        if a[j]>a[z]:
            j=z
    ans+=1
    ans2[i].append(i)
    ans2[i].append(j)
    a[i],a[j]=a[j],a[i]
    if a==sorted(a):
        break
print(a)
for x in ans2:
    if len(x)==0:
        break
    else:
        print(*x)
