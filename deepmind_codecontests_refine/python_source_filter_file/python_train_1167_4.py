# cook your dish here
t = int(input())

while t>0:
	tuples = []
	n = int(input())
	while n >0:
		tup = []
		p = input().split()
		a = int(p[0])
		b = int(p[1])
		tup.append(a)
		tup.append(b)
		tuples.append(tup)
		n = n-1
	tuples.sort(key = lambda x: x[1])
	
	a = 0
	b = 0
	ans = ''
	do = 'YES'
	for tup in tuples:
	    a , b = tup[0] - a, tup[1] -b
	    if a< 0 or b < 0:
	        do = 'NO'
	        break
	    for i in range(a):
	    	ans+='R'
	    for i in range(b):
	    	ans+='U'
	    a = tup[0]
	    b = tup[1]
	if do == "NO":
		print("NO")
	else:
		print(do)
		print(ans)
	   
	t = t-1
