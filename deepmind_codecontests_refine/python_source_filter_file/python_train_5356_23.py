n = list(map(int,input().split(' ')))
arr = []
c = False
for  i in range(n[0]):
	t = int(input())
	if(t % n[1] in arr):
		print(i+1)
		c = True
		break
	else:
		arr.append(t % n[1])
if(c==False):
	print(-1)