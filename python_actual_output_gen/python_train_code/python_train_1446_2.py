t = int(input())
while(t!=0):
	t-=1
	n = int(input())
	s = input()
	s1 = s[::-1]
	s_one = n-(s1.find('1'))
	s1_one = s.find('1')+1
	print(s1_one,s_one)
	if s.find('1') != -1:
		print(max(s1_one,s_one)*2)
	else:
		print(n)
