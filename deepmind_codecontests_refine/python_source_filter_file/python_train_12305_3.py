q=int(input())
a=[]
for j in range(50):
        a.append(3**j)
a.reverse()
s=sum(a)
for i in range(q):
    ans=s
    n=int(input())
    for k in range(25):
        if(ans-a[k]>=n):
            ans=ans-a[k]
    print(ans)