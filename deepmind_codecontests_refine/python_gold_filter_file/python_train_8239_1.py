n=int(input())
l=[int(x) for x in input().split()]
s=sum(l)
ans=[1]
su=l[0]
if l[0]>s//2:
    print(1)
    print(1)
    exit(0)
flag=0
for i in range(1,n):
    if 2*l[i]<=l[0]:
        ans.append(i+1)
        su+=l[i]
    if su>s//2:
        flag=1
        break
if flag==0:
    print(0)
else:
    print(len(ans))
    print(*ans)