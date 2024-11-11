k,d,t=input().split()

k,d,t=int(k),int(d),int(t)
time=0

if True:
	m=int((k-1)/d)*d+d-k
	#print(m)
	tc=k+0.5*m
	ta=k+m
	l=int(t/tc)
	time=ta*l
	#print(tc)
	#print(ta)
	#print(time)
	#print(l)
	if (k>t-l*tc):
		time+=t-l*tc
		print(t-l*tc)
	else:
		time+=k
		time+=2*(t-l*tc-k)
print(time)
