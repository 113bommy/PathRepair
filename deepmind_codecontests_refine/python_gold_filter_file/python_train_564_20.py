def check_subsequence():
	n, m = len(s), len(t)
	i, j = 0, 0 
	while i < n and j < m:
		if s[i] == t[j]:
			i += 1 
			j += 1 
		else:
			i += 1 
	if j != m :
		return False 
	return True 
s = input()
t = input()
flag = False 
#print(len(s), len(t))
if len(s) < len(t):
	print("need tree")
else:
	for i in t:
		if t.count(i) > s.count(i):
			flag = True
			print("need tree") 
			break 
	if not flag:
		if not check_subsequence():
			if len(s) > len(t):
				print("both")
			else:
				print("array")
		elif check_subsequence():
			print('automaton')
		else:
			print("need tree")