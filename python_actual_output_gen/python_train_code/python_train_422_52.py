kb 		= 'qwertyuiopasdfghjkl;zxcvbnm,./'

vecotor = input().lower()	
text 	= input().lower()
result 	= ''

if vecotor == 'r': delta = 1
else: delta = -1

for char in text:
	result += kb[kb.rfind(char) + delta]
	
print(result, end='')