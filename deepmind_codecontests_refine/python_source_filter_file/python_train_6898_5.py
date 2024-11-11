def solve():
	s = input()
	score = 0
	ti, i, tn, n = 0, 0, 0, 0
	last = '0'
	round = True
	while s.find('1') != -1:
		# print(s)
		j =0
		while j < len(s):
			if s[j] == '1' and last == '0':
				ti = s.index(s[j])
				tn=1
				last = '1'
			elif s[j] == '1' and last == '1':		
				tn+=1
				last = '1'
			elif s[j] ==  '0' and last == '1':
				if tn > n:
					n, i = tn, ti
				last= '0' 
			j+=1
		if tn > n:
				n, i = tn, ti
		if round:
			score +=n
		# print(ti,i,tn,n,score)
		s = s.replace('1'*n, '')
		ti, i, tn, n = 0, 0, 0, 0
		round = not round
	return score

n = int(input())
for _ in range(n):
	print(solve())