import heapq
n,M=map(int,input().split())
M=-M
ti=list(map(int,input().split()))
ti=map(lambda i:-1*i ,ti)
li=[]
ans=[]
heapq.heapify(li)
summ=0
for i in ti:
    summ+=i
    ab=summ
    if summ>=M:
        heapq.heappush(li,i)
        ans.append(0)
    if summ<M:
        count = 0
        a=li.copy()
        while summ<M:
            summ-=a[0]
            count+=1
            heapq.heappop(a)
        heapq.heappush(li,i)
        summ=ab
        ans.append(count)
print(*ans)