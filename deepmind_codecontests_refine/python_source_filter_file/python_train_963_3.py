def solution(A):
	m = max(A) 
	if m < 1: 
		return 1
	if len(A) == 1: 
		return 2 if A[0] == 1 else 1	
	l = [0] * m 
	for i in range(len(A)): 
		if A[i] > 0: 
			if l[A[i] - 1] != 1: 
				l[A[i] - 1] = 1
	for i in range(len(l)): 
		if l[i] == 0: 
			return i + 1
	return i + 2	
a=int(input())
for i in range(a):
    b=int(input())
    x1=[]
    x2=[]
    c=[int(x) for x in input().split()]
    d=[0]*101
    for j in range(b):
        d[c[j]]=d[c[j]]+1
    for j in range(10):
        if(d[j]>=2):
            x1.append(j)
            x2.append(j)
        if(d[j]==1):
            x1.append(j)
    if(x1==[]):
        a1=0
    else:
        if(min(x1)>0):
            a1=0
        else:
            a1=solution(x1)
    if(x2==[]):
        a2=0
    else:
        if(min(x2)>0):
            a2=0
        else:
            a2=solution(x2)
    print(a1+a2)
