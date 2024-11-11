from collections import deque
import heapq
for nt in range(int(input())):
	n=int(input())
	if n==1:
		print (1)
		continue
	if n==2:
		print (1,2)
		continue
	if True:
		ans=[-1]*n
		q2=[]
		ans[(n+1)//2-1]=1
		q2.append([-(n-((n+1)//2+1)+1),(n+1)//2+1,n])
		q2.append([-((n+1)//2)+1,1,(n+1)//2-1])
		heapq.heapify(q2)
		flag=1
		k=2
		while len(q2)!=0:
			group = heapq.heappop(q2)
			group[0] = -1*group[0]
			if group[0]==1:
				ans[group[1]-1]=k
			elif group[0]==2:
				ans[group[1]-1]=k
				heapq.heappush(q2,[-1,group[1]+1,group[2]])
			elif group[0]%2:
				ans[group[1]+group[0]//2-1]=k
				heapq.heappush(q2,([-(group[0]//2),group[1],group[1]+group[0]//2-1]))
				heapq.heappush(q2,([-(group[0]//2),group[1]+group[0]//2+1,group[2]]))
			else:
				ans[group[1]+group[0]//2-2]=k
				heapq.heappush(q2,([-(group[0]//2)+1,group[1],group[1]+group[0]//2-2]))
				heapq.heappush(q2,([-(group[0]//2),group[1]+group[0]//2,group[2]]))
			k+=1
		for i in range(n):
			if ans[i]==-1:
				ans[i]=k
				k+=1
		print (*ans)


