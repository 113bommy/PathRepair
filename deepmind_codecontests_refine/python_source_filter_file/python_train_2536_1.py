string = input()

if string.startswith('http'):
    protocol = string[:4]
    string = string[4:]
else:
	protocol = string[:3]
	string = string[3:]
    
domain_end = string.find('ru')

domain_name = string[:domain_end]
context = string[domain_end + 2:]

result = protocol + '://' + domain_name + '.ru'

if len(context) > 0:
    result += '/' + context
    
print(result)