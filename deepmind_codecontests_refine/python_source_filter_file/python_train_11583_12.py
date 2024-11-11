# Social Distancing 
def min(a,b):
	if a < b:
		return a
	else:
		return b

def maxify(x1,x2,k):
	# x1 and x2 are also valid indices for new people
	# x1 is the right-most allowed seat no, and x2 is the left-most one --> little counter-intuitive
	print(x2,x1,k)
	count = 1 
	r = x2 + (k+1)
	while r <= x1:
		count += 1 
		r = x2 + (k+1)
	return count 

t = int(input())

for i in range(0,t):
	n, k = input().split()
	n = int(n)
	k = int(k)
	string = list(input())
	length = len(string)
	l2r = [False] * length
	r2l = [False] * length
	#print(length)
	j1 = 0
	while j1 < length:
		if string[j1] == '0':
			l2r[j1] = True 
		if string[j1] == '1':
			j1 += k
		j1 += 1

	j2 = 1
	while j2 <= length:
		#print("----")
		#print(-j2,string[-j2])
		if string[-j2] == '1':
			j2 += k
		else:
			r2l[-j2] = True 
		j2 += 1

	#print(l2r)
	#print(r2l)

	j = 0
	ans = 0
	while j < length:
		#print(j)
		if (l2r[j] == True) and (r2l[j] == True):
			ans += 1
			for kk in range(j+1,j+k+1):
				if kk < length:
					l2r[kk] = False 
				#r2l[kk] = False # Not necessary
			j += j+k
		j += 1 
	#print(l2r)
	#print(r2l)

	print(ans)









		
