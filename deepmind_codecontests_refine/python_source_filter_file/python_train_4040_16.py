import heapq
n,m = map(int,input().split())
AB =[tuple(map(int,input().split())) for i in range(n)]
ans,memo=0,0
hq=[]
AB.sort(key=lambda tup:tup[0])
for day in range(m):
	for i in range(memo,n):
		if AB[i][0]<=(day+1):
			heapq.push(hq,AB[i][1])
			memo+=1
		else:
			break
	if len(hq):	
		ans += -heapq.heappop(hq)
print(ans)


