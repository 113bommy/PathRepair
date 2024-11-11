from sys import * 
n = int(stdin.readline())
A = {}
i ,j = 1,0
# print(i,j)
for l in range(n):
	x, y = stdin.readline().split("\n")
	x, k = map(str,x.split())
	k = int(k)
	if(x=='?'):
		stdout.write(str(min(A[k]-i , j-A[k]))+'\n')
	elif(x=='R'):
		j += 1
		A[k] = j		
	else:
		i -= 1
		A[k] = i
