import string

# Input: a word of type string.

# Output: convert the give string as follows.
# 	1. delete all the vowels.
# 	2. insert the character "." before each consonant.
# 	3. replace all the Uppercase consonants with their corresponding lowercase ones. 

word = input()
word = word.lower()

word_as_list = list(word)

for x in range(len(word_as_list)):
	if word_as_list[x] in 'aeiou':
		word_as_list[x] = ''

newWord = ''.join(word_as_list)

for x in range(len(word_as_list)):
	if word_as_list[x] not in 'aeiou ': # space added so that we can avoid empty strings that are in the list.
		word_as_list[x] = '.' + word_as_list[x]

finalWord = ''.join(word_as_list)

print(finalWord)