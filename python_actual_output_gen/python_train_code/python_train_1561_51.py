word = input()
output = ""

for char in word.lower():
	if char not in "aeoui":
		output += "." + char

print (output)