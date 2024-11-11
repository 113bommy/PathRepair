import math
for ii in range(int(input())):
	n = int(input())
	s = input()
	dic = {}
	dic['X0Y0'] = 0 
	curr = [0,0]
	size = math.inf
	for i in range(len(s)) :
		#print(i)
		if s[i] == "L":
			curr[0]-= 1
		if s[i] == "R":
			curr[0]+= 1
		if s[i] == "U":
			curr[1] += 1
		if s[i] == "D":
			curr[1] -= 1
		a = "X"+ str(curr[0])+"Y"+str(curr[1])
		#print(a)
		if a not in dic :
			dic[a] = i+1
		else :
			if i-dic[a]+1 < size :
				l = dic[a]
				r = i
				size = r-l+1
				dic[a] = i+1
		#print(dic)
	if math.isfinite(size):
		print(l+1,r+1)
	else :
		print(-1)

