from heapq import*
R=L=[]
B=t=0
Q,*E=open(0)
for e in E:
	if' 'in e:_,a,b=map(int,e.split());t=1-t;a*=2*t-1;c=heappushpop([L,R][t],a);heappush([R,L][t],-c);B+=b+a-c-c
	else:print(-L[0],B-L[0]*t)