#input

n,k=map(int,input().split())
a=[]

for i in range(n):
	a.append(str(input()))



#variables
x=0



#main

for i in range(n):
	t=True
	for j in range(0,k):
			if str(j) not in a[i]:
				t=False
	if t:
		x+=1

print(x)