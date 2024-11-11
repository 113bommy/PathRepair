t = int(input())
alphabets = 'abcdefghijklmnopqrstuvwxyz'
fin = []
output=""
while t:
	s = input()
	s = s.split(' ')
	fin.append(int(s[0]))
	fin.append(int(s[1]))
	lis = alphabets[:fin[1]]
	lis = list(lis)
	for i in range(fin[0]):
		output+=lis[i%fin[1]]
	print(fin , output)
	fin = []
	output=""
	t=t-1