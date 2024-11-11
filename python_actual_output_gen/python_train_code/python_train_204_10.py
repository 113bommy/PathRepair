n,k=map(int,input().split())
nos=list(map(int,input().split()))
li=[nos]

for i in range(n-1):
	nos=list(map(int,input().split()))
	for j in range(len(li)):
		if nos[0]>li[j][0] or (nos[0]==li[j][0] and nos[1]<=li[j][1]):
			li.insert(j,nos)
			break
		elif j==len(li):
			li.append(nos)

print(li.count(li[k]))