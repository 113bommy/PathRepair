n = int(input())
sweets = list(map(int,input().split()))
tab = [0]*20001
for i in range(n):
	for j in range(i+1,n):
		if sweets[i]+sweets[j] > 20000: 
			print ("dupa")
		else:
			tab[sweets[i]+sweets[j]] += 1
m = 0
for i in range(20001):
	m = max(m,tab[i])
print(m)