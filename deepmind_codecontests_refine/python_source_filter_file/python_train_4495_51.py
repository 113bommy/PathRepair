word = input()
output = ""

for char in word.lower():
	if char not in "aeou":
		output += "." + char

print (output)