n , k = map(int,input().split())
seq = list(map(int,input().split()))
seq.sort()
ans = seq[0]-1
count = 0
if(k>0 and k<=n):
	ans = seq[k-1]
for i in range(n):
	if(seq[i]<=ans):
		count+=1
	else:
		break
if(ans<1 or count!=k):
	# print(ans,count,k,seq[0]-1)
	print("-1")
else:
	print(ans)