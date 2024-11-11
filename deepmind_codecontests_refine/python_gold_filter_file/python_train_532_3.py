n,m,k = list(map(int,input().split()))
powers = list(map(int,input().split()))
schools = list(map(int,input().split()))
chosen = list(map(int,input().split()))
wyn = 0
for i in chosen:
	s = schools[i-1]
	for j in range(n):
		if schools[j] == s and powers[j] > powers[i-1]:
			wyn += 1
			schools[i-1] = m+wyn*1000
			break
print(wyn)