# Задачка C

# гласные
vowels = 'aeiou'
word = input()
consonants = word[0] not in vowels
duplicates = 0
result = ''
term = word[0]
for p, w in zip(word, word[1:]):
	if w not in vowels: consonants += 1
	else:
		consonants = duplicates = 0
	if consonants > 0: duplicates += p==w
	if consonants > 2 and duplicates != consonants-1:
		result += term + ' ' + w 
		consonants = duplicates = 0
		term = ''
	else:
		term += w

result += term
if result.startswith(' '): result == result[1:]
print(result)




