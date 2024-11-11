q=lambda:map(int,input().split())
qi=lambda:int(input())
qs=lambda:input().split()
n,=q()
ans=[]
for i in range(n):
    a,x,y=qs()
    x,y=map(int,(x,y))
    if x>=2400:
        ans.append(y-x)
ans=[i for i in ans if i>0]
print('YES' if len(ans) else 'NO')