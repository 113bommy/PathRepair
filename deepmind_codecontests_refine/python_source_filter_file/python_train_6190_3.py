def clean(n,w,i):
	for j in range(i+1,n):
		if 0 not in [w[j-1],w[j-2]]:
			w[j] = 0
		elif 1 not in [w[j-1],w[j-2]]:
			w[j] = 1
		else:
			w[j] = 2
	return ''.join([chr(ord('a')+x) for x in w])
def solve():
	n, p = map(int, input().split())
	w = [ord(c)-ord('a') for c in input()]
	if p==1:
		return 'NO'
	elif p==2:
		if n==1 and w[0]==0:
			return 'b'
		elif n==2 and w[0]==0:
			return 'ba'
		else:
			return 'NO'
	elif n==1:
		if w[0]==p-1:
			return 'NO'
		else:
			return chr(ord('a')+1)
	for i in range(n-1,1,-1):
		for k in range(1,3+1):
			if w[i]+k not in [w[i-1],w[i-2]] and w[i]+k < p:
				w[i] += k
				return clean(n,w,i)
	for k in range(1,2+1):
		if w[1]+k not in [w[0]] and w[1]+k < p:
			w[1] += k
			return clean(n,w,1)
	if w[0]+1 < p:
		w[0] += 1
		w[1] = 0
		return clean(n,w,1)
	return 'NO'
print(solve())