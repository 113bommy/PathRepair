t = int(input())
a = 1
b = 0
for i in range(t):
	x = int(input())
	if str(x) == '111':
	    b = 6
	if len(str(x)) == 4:
	    for i in range(1, 10):
			    if str(i) in str(x):
				    a = i*10
	elif len(str(x)) == 3 and x != 111:
	    for i in range(1, 10):
	        if str(i) in str(x):
	            a = (i*10)-4
	elif len(str(x)) == 2 and x != 11:
	    for i in range(1, 10):
	        if str(i) in str(x):
	            a = (i*10)-7
	elif len(str(x)) == 1 and x != 1:
	    for i in range(1, 10):
	        if str(i) in str(x):
	            a = (i*10)-9
	if str(x) == '1':
	    b = 1
	elif str(x) == '11':
	    b = 3

	if '1' in str(x) and x != 1111:
	    print(b)
	else:
	    print(a)