data = input()
data = data.lower().replace(" ", "")
vowels = ['a', 'e', 'i', 'o', 'u']
output = ''
for value in data:
	if value not in vowels:
		output += "." + value
print(output)
