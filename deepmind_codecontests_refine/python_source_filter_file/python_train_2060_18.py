n = list(map(int,input()))[::-1]
n.append(0)
for i in range(len(n)):
	if n[i] >= 6 or (n[i] == 5 and n[i+1] >= 5):
    	n[i] = 10 - n[i]
        n[i+1] += 1
print(sum(n))