a = input() 
b = input()

fq = []
for i in range(1, 100):
        fq.append(0)

for i in a:
	fq[ord(i) - ord('A')] +=1


sol = "YES" 

for i in b:
	if i != ' ' and fq[ord(i) - ord('A')] > 0:
		fq[ord(i) - ord('A')] -= 1
	elif i != ' ':
		sol = "NO"
		break

print (sol)
