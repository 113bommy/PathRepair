
n = int(input())
s = input()
d = {}

for i in range(n-2):
	try:
		d[s[i:i+2]] += 1

	except:
		d[s[i:i+2]] = 1
man = -1
si = ''
for i in d.keys():
	if d[i] > man:
		man = d[i] 
		si = i
print(si)