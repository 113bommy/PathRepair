n = int(input())
a = [0]*(10)
s= input()

def get_r_index():
	ind = -1
	while a[ind]!=0:
		ind -= 1
	return ind

def get_l_index():
	ind = 0
	while a[ind]!=0:
		ind += 1
	return ind

for i in range(n):
	if s[i]=='R':
		a[get_r_index()] = 1
	elif s[i]=='L':
		a[get_l_index()] = 1
	else:
		pos = int(s[i])
		a[pos] = 0

for i in a:
	print(i, end='')