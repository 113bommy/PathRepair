n = int(input())
ls = []
res = ''
for i in range(n):
	ls.append(list(map(int,input().split())))

for i in range(n-1):
	if ls[i][0]!=ls[i][1]:
		res = "rated"
		break

if res != 'rated':
	for i in range(n-1):
		if ls[i][1]<ls[i+1][1]:
			res = "unrated"
			break
		else:
			res = "maybe"


print(res)
