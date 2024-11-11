t = int(input())
for u in range(t):
	n,k = list(map(int,input().split()))
	a = list(map(int,input().split()))
	picks = [0]*n
	count = [0]*(n-k+1)
	tmp = 0
	tmpact = [0,0]
	for i in range(1,n-1):
		if a[i] > a[i-1] and a[i] > a[i+1]:
			picks[i] = 1
	for i in range(k-1):
		if picks[i] == 1:
			tmp += 1
	count[0] = tmp
	for i in range(k,n):
		if picks[i-k+1] == 1:
			tmp -= 1
		if picks[i-1] == 1:
			tmp += 1
		count[i-k+1] = tmp
	for i in range(n-k+1):
		if count[i] > tmpact[0]:
			tmpact[1] = i+1
			tmpact[0] = count[i]
	print(tmpact[0]+1,tmpact[1])