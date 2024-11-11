
n = int(input())
zo = input()

dr = [0]
ml = 0
mini = {0: 0}

for i in range(n):
	
	if zo[i]=='0':
		dr.append(dr[i]-1)
	else:
		dr.append(dr[i]+1)
	if not(dr[i+1] in mini):
		mini[dr[i+1]] = i+1
	else:
		ml = max(ml, i+1 - mini[dr[i+1]])

print(ml)
