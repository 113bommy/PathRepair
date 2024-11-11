new_login = input()
count_logins = int(input())
logins = []
for _ in range(count_logins):
	logins.append(input())
def check_login(pattern, login):
	length = len(pattern)
	if length != len(login):
		return False
	for i in range(length):
		if pattern[i].lower() == login[i].lower():
			continue
		rules = [ set('1iIlL'), set('O0')]
		not_same = True
		for rule in rules:
			if (pattern[i] in rule) and (login[i] in rule):
				not_same = False
				break
		if not_same:
			return False
	return True

same = False
for current_login in logins:
	if check_login(current_login, new_login):
		same = True
		break
if same:
	print('No')
else:
	print('Yes')
