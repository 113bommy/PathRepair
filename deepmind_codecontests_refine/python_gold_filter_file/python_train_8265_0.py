def solve(m, x,y , w,z):
	for i in range(8):
		for j in range(8):
			if m[i][j]:
				a, pa = movePossible(x,y , i,j)
				b, pb = movePossible(w,z , i,j)
				if a and b and pa==pb:
					return True
	return False
	
def movePossible(x,y , w,z):
	a = x-w
	b = y-z
	pos=False
	ka=a//2
	kb=b//2
	if a%2==0 and b%2==0 and (ka+kb)%2==0:
		pos=True
	
	return pos, ka%2

t = int(input())
for _c in range(t):
	m = []
	primo = True
	for i in range(8):
		m.append([])
		s = input()
		k=0
		for c in s:	
			if c=='#':
				m[i].append( False )
			else:
				m[i].append( True )
			
			if c=='K' and primo:
				x=i
				y= k
				primo = False
			if c=='K' and (not primo):
				w=i
				z= k
			k+=1
	
	if solve(m, x,y , w,z):
		print("YES")
	else:
		print("NO")
	
	if _c!=t-1: m=input()
	
	
	
