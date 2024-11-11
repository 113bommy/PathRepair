from heapq import heappop,heappush,heapify
n=int(input())
a=list(map(int,input().split()))
left=[0]*n
lst=a[:n]
s=sum(lst)
heapify(lst)
for i in range(n):
    heappush(lst,a[n+i])
    x=heappop(lst)
    if i==0:
        left[0]=s+a[n]-x
    else:
        left[i]=left[i-1]+a[n+i]-x
left=[s]+left
right=[0]*n
lst=[]
for i in range(2*n,3*n):
    lst.append(-a[i])
s=-sum(lst)
heapify(lst)
for i in range(n):
    heappush(lst,-a[2*n-1+i])
    x=-heappop(lst)
    if i==0:
        right[n-1]=s+a[2*n-1]-x
    else:
        right[n-1-i]=right[n-i]+a[2*n-1-i]-x
right+=[s]
ans=-float("inf")
for i in range(n):
    ans=max(ans,left[i]-right[i])
print(ans)