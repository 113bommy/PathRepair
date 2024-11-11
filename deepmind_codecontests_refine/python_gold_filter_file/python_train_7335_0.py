n=int(input())
w1=0
w2=0
l1=[]
l2=[]
last1=True
for i in range(n):
	t=int(input())
	if t > 0:
		w1+=t
		l1.append(t)
		last1=True
	else:
		w2+=-t
		l2.append(-t)
		last1=False
# print (w1,w2)
if w1 > w2:
	print ("first")
	exit(0)
if w1 < w2:
	print ("second")
	exit(0)
if l1 > l2:
	print ("first")
elif l1 < l2:
	print ("second")
else:
	if last1:
		print ("first")
	else:
		print ("second")