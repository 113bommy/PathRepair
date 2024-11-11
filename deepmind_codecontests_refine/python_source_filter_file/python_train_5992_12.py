n = int(input())
vals = [int(i) for i in input().split()]
s = sum(vals)//n*2
for i in range(n):
	for j in range(i+1,n):
		if(vals[i] + vals[j] == s):
			print(i+1,j+1)
			vals[i] = 0
			vals[j] = 0
