t=int(input())
for _ in range(t):
	l=int(input())
	lt = [str(i) for i in input().split()]
	s=lt[0]
	for i in range(1,len(lt)):
		if(s[i] == lt[i][0]):
			s=s+lt[i][1]
		else:
			s=s+lt[i]
	if(len(s)!=l):
		for j in range(l-len(s)):
			s=s+'a'
	print(s)