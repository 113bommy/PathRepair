n,k = map(int,input().split())
l = list(map(int,input().split()))
while(True):
	if(len(l)==0):
		break
	if(l[0]<=k):
		l.remove(l[0])
	elif(l[len(l)-1]<=k):
		del l[len(l)-1]
	else:
		break
print(n-len(l))