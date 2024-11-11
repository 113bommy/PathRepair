n=int(    input()  )
l=list(map(int, input().strip().split()))

h=[0 for a in range(0, 3001)]

for i in l:
	h[i]+=1
for i in range(1,3001):
	if h[ i]==0: 
		print(i)
		break