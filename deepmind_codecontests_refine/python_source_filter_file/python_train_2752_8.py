n = int(input())

inpt = list(map(int,input().split(" ")))[:n]

count = 0
policeman = 0

for i in inpt:
	if(i>0):
		policeman+= i
	else:
		if(policeman - i < 0):
			count+=1
		else:
			policeman-=1
print(count)