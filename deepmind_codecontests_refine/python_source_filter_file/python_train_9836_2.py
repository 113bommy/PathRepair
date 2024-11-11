# your code goes here
n=int(input())
w=[]
h=[]
sum=0
for i in range(n):
	w1,h1=map(int,input().split())
	w.append(w1)
	h.append(h1)

	
	sum+=w1
h.sort(reverse=True)	
	
for i in range(n):
	if h[i] == h[0]:
		print((sum-w[i])*h[1])
	else:
		print((sum-w[i])*h[0])
	

	