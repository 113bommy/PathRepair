number = input()
letter = input()
length = len(letter)
verifier = False
for i in range (1, length):
	if letter[i-1] == letter[i]:
		verifier = True
		print("YES")
		print(letter[i-1:i+1])
		break
if verifier == False:
	print("NO")
