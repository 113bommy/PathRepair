yo=list(map(int,input().split()))
a=yo[0]
b=yo[1]
c=yo[2]
d=yo[3]
score1=max(0.3*a,0.004*a*c)
score2=max(0.3*b,0.004*b*d)
if score1>score2:
	print('Misha')
elif score2>score1:
	print('Vasya')
else:
	print('Tie')		