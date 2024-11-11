n=int(input())
a=list(map(int,input().split()))
a.sort()
ans=[]
R=a.pop()
L=a.pop(0)
s=L
if a:
    while a[-1]>0:
        r=a.pop()
        ans.append([s,r])
        s=s-r
        if not a:break
ans.append([R,s])
s=R-s
while a:
    L=a.pop()
    ans.append([s,L])
    s=s-L
print(s)
for x in ans:
    print(*x)
