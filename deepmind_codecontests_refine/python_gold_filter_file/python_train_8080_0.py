n = int(input())
mot = input()
m = int(input())
myList = []
myList2 = []
char = []
for i in range(m):
	myList.append(input())
for x in myList:
	if(len(x) == n):
		meme = True
		for i,c in enumerate(mot):
			if c != '*':
				if x[i] != c:
					meme = False
			else:
				if x[i] in mot:
					meme = False
		if meme:
			myList2.append(x)
for c in myList2[0]:
	if c not in mot and c not in char:
		char.append(c)
for j in myList2:
	for c in char[::]:
		if c not in j:
			char.remove(c)
			
print(len(char))
	
			
			