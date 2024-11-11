input();l = ''.join(input().split())
ctr = 0
ans = 0
skip = False
for i in range(len(l)-2):
	if (i >= 2 and not skip) or i == len(l)-3:
		if l[i:i+3] == '101' and l[i-2:i+1] != '101':
			ctr = 1
			skip = True
			continue
		elif l[i:i+3] == '101' and l[i-2:i+1] == '101':
			ctr += 1
			skip = True
			continue
		else:
			ans += -(-ctr//2)
			# print(ctr)
			ctr = 0
	elif i < 2 and not skip:
		if l[i:i+3] == '101':
			ctr += 1
			skip = True
			continue
		if i == len(l)-3:
			ans += ctr
			ctr = 0
	skip = False
	# print(ctr,'out')
print(ans -(-ctr//2))