s = input()
n = len(s)
flag, p = 0, 0
if n < 26 :
	print(-1)
	exit(0)
else :
	f = []
	for i in range(26) :
		f.append(0)
	for i in range(0, n-25) :
		cnt1, cnt2 = 0, 0
		for j in range(26) :
			f[j] = 0
		for j in range(26) :
			if s[i+j] == '?' :
				cnt1 = cnt1 + 1
			elif f[ord(s[i+j]) - ord('A')] == 0 :
				f[ord(s[i+j]) - ord('A')] = 1
				cnt2 = cnt2 + 1
		if cnt1 + cnt2 == 26 :
			flag = 1
			p = i
			break
if flag == 1:
	for i in range (p) :
		if s[i] == '?' :
			print('A', end = "")
		else :
			print(s[i], end = "")
	for i in range(p, n) :
		if s[i] == '?' :
			tag = 0
			for j in range(26) :
				if f[j] == 0 :
					f[j] = 1
					tag = 1
					print(chr(ord('A')+j), end = "")
					break
			if tag == 0 :
				print('A',end = "")
		else :
			print(s[i], end = "")
	print("")
else :
	print(-1)
