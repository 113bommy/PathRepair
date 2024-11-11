original = input()
perm = input()

if ''.join(sorted(original)) == ''.join(sorted(perm)):
	o = sorted(original)
	if o[0] == '0':
		for i in range(0,len(o)):
			if o[i] != '0':
				o[0] = o[i]
				o[i] = '0'
				break
		for i in range(0,len(o)):
			if o[i] != perm[i]:
				print ("WRONG_ANSWER")
				exit()
	print ("OK")
else:
	print ("WRONG_ANSWER")
