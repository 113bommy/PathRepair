s = input()
ar = ['B','u','l','b','a','s','r']
found = [0,0,0,0,0,0,0]

for i in range(len(s)):
	for j in range(len(ar)):
		if(s[i]==ar[j]):
			found[j] +=1
			break

found[4]/=2
found[1]/=2
if(len(found) == len(ar)):
	print(min(found))
else:
	print(0)

