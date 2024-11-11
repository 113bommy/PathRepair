inp = input().split(' ')
vladik = int(inp[0])
valera = int(inp[1])
sub = 1
while(vladik>=0 and valera>=0):
	if sub%2!=0:
		vladik-=sub
		sub+=1
	elif sub%2==0:
		valera-=sub
		sub+=1
	if(valera<0):
		print("Valera")
		break
	elif(vladik<0):
		print("Vladik")
		break