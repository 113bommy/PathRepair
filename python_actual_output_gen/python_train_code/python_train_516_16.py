s = input()
vowels = {'a','e','i','o','u'}
output = ''

for i in range(len(s)-1):
	if s[i] not in vowels and s[i+1] not in vowels and s[i] != 'n':
		output = 'No'
		break

if not output:
	output = 'Yes'

if s[len(s)-1] not in vowels or s[len(s)-1] != 'n':
	output = 'No'

print(output)