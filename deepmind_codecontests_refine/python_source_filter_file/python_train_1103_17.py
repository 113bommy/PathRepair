# your code goes here
k = int(input())
starr = list(input())
n = len(starr)
sum = 0
for i in range(n):
	starr[i] = int(starr[i])
	sum += starr[i]
#print(starr)
starr.sort()
#print(starr)
ctr = 0
for a in starr:
	if sum >= k:
		break
	sum -= starr[i]
	sum += 9
	ctr += 1
print(int(ctr))