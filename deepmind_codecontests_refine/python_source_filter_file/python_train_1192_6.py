a = "qwertyuiop"
b = "asdfghjkl;"
c = "zxvcbnm,./"
s1 = input()
s2 = input()
k = 1
if(s1 == 'R'):
	k = -1
for i in range(len(s2)):
	for j in range(10):
		if(s2[i] == a[j]):
			print(a[j+k], end="")
			break
		elif(s2[i] == b[j]):
			print(b[j+k], end="")
			break
		elif(s2[i] == c[j]):
			print(c[j+k], end="")
			break