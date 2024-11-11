''' author: Priyank Koul, PES University, Bengaluru'''
for _ in range(int(input())):
	#x= int(input())
	li= list(map(int, input().strip().split()))
	a=li[0]
	b=li[1]
	if(a>b):
		print(int(b*(b+1)/2))
	else:
		#print(int((a*(a+1)/2)-a+1))
		print(int((a-1)*(a)/2)+1)