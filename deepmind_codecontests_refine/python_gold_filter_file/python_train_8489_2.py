n, k, t = map(int,input().split())
block = t*n//100
total = n*k*t//100
remain = total-block*k
for i in range(1,n+1):
	if i <= block:
		print(k,end=' ')
	elif i == block + 1:
		print(remain,end=' ')
	else:
		print(0,end=' ')
