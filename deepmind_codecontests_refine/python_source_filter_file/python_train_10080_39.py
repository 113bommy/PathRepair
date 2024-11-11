s=input()
K=int(input())

a=set([])

for x in range(len(s)):
	for y in range(x, len(s)):
		a.add(s[x:y+1])

print(sorted(a)[K-1])
