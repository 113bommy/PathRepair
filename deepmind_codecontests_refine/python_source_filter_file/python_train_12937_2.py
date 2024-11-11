import heapq
from collections import defaultdict
n=int(input())
b=list(map(int,input().split()))
cnt=defaultdict(lambda:0)
for j in b:
    cnt[j]+=1

li=[]
for j in list(set(b)):
    li.append([-cnt[j],j])

heapq.heapify(li)
l=len(li)
ans=[]
while(l>=3):
    ball1=heapq.heappop(li)
    ball2 = heapq.heappop(li)
    ball3 = heapq.heappop(li)
    ans.append([ball1[1],ball2[1],ball3[1]])
    cnt1=ball1[0]+1
    if cnt1!=0:
        heapq.heappush(li,[cnt1,ball1[1]])

    else:
        l+=-1

    cnt2 = ball2[0] + 1
    if cnt2 != 0:
        heapq.heappush(li, [cnt2, ball2[1]])

    else:
        l+=-1

    cnt3 = ball3[0] + 1
    if cnt3 != 0:
        heapq.heappush(li, [cnt3, ball3[1]])

    else:
        l+=-1


print(len(ans))
for j in ans:
    j.sort()
    print(*j)



