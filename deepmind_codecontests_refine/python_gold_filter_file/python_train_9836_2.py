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
a=sorted(h,reverse=True)	
	
for i in range(n):
	if h[i] == a[0]:
		print((sum-w[i])*a[1])
	else:
		print((sum-w[i])*a[0])
	

	