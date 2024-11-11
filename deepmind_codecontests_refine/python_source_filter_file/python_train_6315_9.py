from heapq import heappop,heappush,heapify
n,m=map(int,input().split())
arr=[[] for i in range(n+1)]
ans=[-1 for i in range(n+1)]
for i in range(m):
    strt,end,req=map(int,input().split())
    arr[strt].append([end,req,i+1])
    ans[end] =i+1
he=[]
req,indx,end=0,0,0
flag=0
for i in range(1,n+1):
    for j in arr[i]:
        heappush(he,j)
    if not he:
        if ans[i] ==-1:
            ans[i] =0
        else:
            ans[i] =m+1
    if he:
        end, req, indx = heappop(he)
        if ans[i] == -1:
            ans[i] =indx
            req-=1
        else:
            if indx <= ans[i]:
                flag=1
                break
            else:
                ans[i] =m+1
        if req >0:
            heappush(he,[end,req,indx])
if flag==1:
    print(-1)
else:
    for i in range(1,n+1):
        if ans[i] !=-1:
            print(ans[i],end=' ')
    print()