input()
for i in map(int,input().split()):
	if i>14 and i%14>=1 or i%14<=6 :
		print('YES')
	else :
	    print('NO')    	