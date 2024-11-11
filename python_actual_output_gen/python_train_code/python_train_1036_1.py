n,k=[int(i) for i in input().split()]
ans=[]
for _ in range(k-1):
    for dv in range(2,n):
        if(n%dv==0):
            ans.append(dv)
            n=n//dv
            break
    if(n==1):
        break
if(len(ans)==k-1):
    for i in ans:
        print(i, end=' ')
        print(n)
else:
    print(-1)