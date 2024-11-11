
st = list(input())


for i in range(len(st) + 1):
	for j in range(26):
		sti = st.copy()

		sti.insert(i, chr(97 + j))
	
		if sti == sti[::-1]:
			print(''.join(sti))
			exit()

print('NA')

