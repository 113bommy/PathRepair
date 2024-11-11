
t=int(input())

a=[1,1,2]
for i in range (t-3):
	a.append(a[-1]+a[-2])
for i in range (1,t+1):
	if a.count(i):
		print("O",end="")
	else :
		print("o",end="")