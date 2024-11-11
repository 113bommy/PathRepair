q,w,e=map(int,input().split())
r=list(map(int,input().split()))
s=sum(r)
if s+(w+1)*(e-1)<q or q<s:
    print('NO')
    exit()
else:
    print('YES')
ans=[[0,0]]
for i in range(w):
    ans.append([ans[-1][1]+1,ans[-1][1]+r[i]])
ans.append([q+1,q+1])
i=-1
while i>-w-1:
    if ans[i][0]-ans[i-1][1]>e:
        ans[i-1][0]+=ans[i][0]-ans[i-1][1]-e
        ans[i-1][1]+=ans[i][0]-ans[i-1][1]-e
    else:
        break
    i-=1
for i in range(w):
    for k in range(ans[i][1],ans[i+1][0]-1):
        print(0,end=' ')
    for k in range(ans[i+1][0]-1,ans[i+1][1]):
        print(i+1,end=' ')
for k in range(ans[i+1][1],ans[i+2][0]-1):
    print(0,end=' ')