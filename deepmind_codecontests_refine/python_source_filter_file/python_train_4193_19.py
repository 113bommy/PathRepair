t = int(input())
for _ in range(t):
	n,m = map(int,input().split())
	conv = []
	for i in range(n):
		conv.append(input())
	ans = 0
	ans+=conv[0][:m-1].count('D')
	for i in conv:
		if(i[-1] == 'R'): ans+=1
	print(ans)