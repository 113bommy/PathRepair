t=int(input())
while t:
    t-=1
    n=int(input())
    a=[int(x) for x in input().split()]
    b=[int(x) for x in input().split()]
    if sum(a)!=sum(b):
        print(-1)
        continue
    ans=[]
    for i in range(n):
        for j in range(n):
            while a[i]>b[i]:
                if  a[j]<b[j]:
                    ans.append((i,j))
                    a[i]-=1
                    a[j]+=1
                else:
                    break

    print(len(ans))
    for i in range(len(ans)):
        print(*ans[i])
