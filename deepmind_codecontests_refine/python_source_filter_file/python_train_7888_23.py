n=int(input())
a=[]
for i in range(n):
    x,l=map(int,input().split())
    a.append([x,l])
a=sorted(a,key=lambda x: x[1])
ans=n
t=a[0][1]
for i in range(1,n):
    if t>a[i][0]:
        ans-=1
    else:
        t=a[i][1]
print(ans)