
l1 = list(input())
l2 = list(input())
cs = list('bcdfghjklmnpqrstvwxy')
vo = list('aeiou')
if len(l1) != len(l2):
	print('No')
	exit()

for i in range(len(l1)):
	if l1[i] in vo and l2[i] in vo or l2[i] in cs and l1[i] in cs:
		continue
	else:
		print('No')
		exit()

print('yes')