import sys
n,m,d = list(map(int,input().split()))
c = [int(x) for x in sys.stdin.readline().split(" ")]
if sum(c)+(len(c)+1)*(d-1)<n:
	print("NO")
else:
	print("YES")
	ans = []
	sf = [0 for i in range(len(c)+1)]
	for i in range(1,len(c)+1):
		sf[~(i)] = sf[~(i-1)]+c[~(i-1)]
	curr_index = 0
	ans = [0 for i in range(n)]
	for i in range(len(c)):
		maxi = curr_index
		for j in range(1,d):
			if n-curr_index-(j+c[i])>=sf[i+1] and maxi+c[i]<=n:
				maxi = max(maxi,curr_index+j)
			else:
				break
		curr_index = maxi+c[i]
		ans[maxi] = c[i]
	idx = 1
	i = 0
	while i<len(ans):
		if ans[i]!=0:
			j = i
			while j<len(ans) and j<i+c[idx-1]:
				ans[j]=idx
				j+=1
			idx+=1
			i=j
		i+=1
	for a in ans:
		print(a,end=' ')			

