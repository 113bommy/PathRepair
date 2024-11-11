letter = input()
letter=letter.lower()
vowels=['a','e','i','o','u']
out=""
for i in letter:
	if i not in vowels:
		out+="."+i
print(out)