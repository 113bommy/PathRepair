a ,b = map(int,input().split())	
q = list(map(int,input().split()))
w = list(map(int,input().split()))
c = 0
for i in q:
	if i in w:
		print(i,end = " ")
		c+=1
if c == 0:
	print("Nothing")