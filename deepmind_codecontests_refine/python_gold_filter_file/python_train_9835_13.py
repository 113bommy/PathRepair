n,x=map(int,input().split())
l=[]
for i in range(n):
    t=list(map(int,input().split()))
    l.append(t)
ans=0;prev=1
for i in l:
    if prev==0:
        ans+=(i[1]-i[0])+1
        prev=i[1]+1
    else:
        ans+=(i[0]-prev)%x
        ans+=(i[1]-i[0])+1
        prev=i[1]+1
print(ans)