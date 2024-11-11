import math
n=int(input())
lst=[float(input()) for _ in range(n)]
nwlst=[round(x,0) for x in lst]
sm=sum(nwlst)
for i in range(n):
	if lst[i]==nwlst[i] or sm==0:
		print(int(nwlst[i]),end=" ")
		continue
	if sm>0:
	 	if lst[i]>nwlst[i]:
	 		nwlst[i]-=1
	 		sm-=1
	if sm<0:
		if lst[i]>nwlst[i]:
			nwlst[i]+=1
			sm+=1
	print((int(nwlst[i])),end=" ")