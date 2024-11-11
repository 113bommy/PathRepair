'''input
5
12
5 4 4 3 2 2 1 1 1 1 1 1
4
4 3 2 1
1
1000000
20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
32
64 64 63 58 58 58 58 58 37 37 37 37 34 34 28 28 28 28 28 28 24 24 19 17 17 17 17 16 16 16 16 11
'''
t=int(input())
for i in range(t):
	n=int(input())
	s=list(map(int,input().split()))
	if n//2<3:
		print("0 0 0")
		continue
	dict={}
	l=[]
	flag=-1
	if s[n//2-1]==s[n//2]:
		flag=s[n//2]
	for j in range(n//2):
		if s[j]!=flag:
			if dict.get(s[j])==None:
				dict[s[j]]=0
				l.append(s[j])
			dict[s[j]]+=1
	total=0
	for j in range(len(l)):
		total+=dict[l[j]]
	if len(l)<3:
		print("0 0 0")
		continue
	g=dict[l[0]]
	s=0
	b=0
	for j in range(1,len(l)):
		if(s<=g):
			s+=dict[l[j]]
		else:
			break
	b=total-g-s
	if g>=s and g>=b:
		print("0 0 0")
		continue
	print(g,s,b)