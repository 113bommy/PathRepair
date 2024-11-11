import math
from sys import stdin,stdout


n=int(stdin.readline().strip())
adj_mtr=[]
for i in range(n):
	adj_mtr.append(list(map(int,list(stdin.readline().strip()))))

for i in range(n):
	for j in range(n):
		if adj_mtr[i][j]==0:
			adj_mtr[i][j]=math.inf

for k in range(n):
	for i in range(n):
		for j in range(n):
			adj_mtr[i][j]=min(adj_mtr[i][j],adj_mtr[i][k]+adj_mtr[k][j])

lpath=int(stdin.readline().strip())
path=list(map(int,stdin.readline().strip().split(' ')))
for i in range(len(path)):
	path[i]-=1


# for i in adj_mtr:
# 	print(i)
# print(path)



ansarr=[path[0]]
start_ptr=0
end_ptr=1
pltn=0

while end_ptr<len(path)-1:
	#print(start_ptr,end_ptr,adj_mtr[path[start_ptr]][path[end_ptr]],pltn+1)
	if adj_mtr[path[start_ptr]][path[end_ptr]]<pltn+1 or (adj_mtr[path[start_ptr]][path[end_ptr]]==pltn+1 and path[start_ptr]==path[end_ptr]):
		ansarr.append(path[end_ptr-1])
		start_ptr=end_ptr-1
		pltn=0
	else:
		end_ptr+=1
		pltn+=1

ansarr.append(path[-1])
for i in range(len(ansarr)):
	ansarr[i]+=1

stdout.write(str(len(ansarr))+"\n")
for i in ansarr:
	stdout.write(str(i)+" ")











