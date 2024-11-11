import heapq as h
def gre(lst,x):
    lst.sort(reverse=True)
    c=0
    s=0
    for i in range(len(lst)):
        s+=lst[i]
        c+=1
        if(s>=x):
            return c
        
def pro(arr,m):
    lst=[arr[0]]
    #h.heapify(lst)
    pre=[0]*len(arr)
    ans=[0]*len(arr)
    pre[0]=arr[0]
    for i in range(1,len(arr)):
        if(pre[i-1]+arr[i]<=m):
            pre[i]=pre[i-1]+arr[i]  # add time
        else:
            req=m-arr[i]
            hav=pre[i-1]-req
            ans[i]=gre(lst,hav)
            pre[i]=pre[i-1]+arr[i]
        lst.append(arr[i])
    print(*ans)
n,m=list(map(int,input().split()))
arr=list(map(int,input().split()))
pro(arr,m)