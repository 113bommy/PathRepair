#author="_rabbit"
n=int(input())
a=list(map(int,input().split()))
ans=[]
s=set()
flag=False
l=0
for i in range(n):
    if a[i] in s:
        ans.append([l+1,i+1])
        l=i+1
        s=set()
        flag=True
    else:
        s.add(a[i])
if(flag==False):
    print(-1)
else:
    print(len(ans))
    ans[len(ans)-1][1]=n
    for i in ans:
        print(i)
