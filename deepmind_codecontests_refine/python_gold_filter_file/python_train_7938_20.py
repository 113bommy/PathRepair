if __name__ == "__main__":
	n,m,x,y = list(map(int, input().split()))
	point = []
	for i in range(1,n+1):
		if i&1:
			for j in range(1,m+1):
				point.append((i,j))
		else:
			for j in range(m,0,-1):
				point.append((i,j))
	point.remove((1,1))
	point.remove((1,y))
	point.remove((x,y))
	point.insert(0,(1,1))
	point.insert(0,(1,y))
	point.insert(0,(x,y))
	for i in point:
		print(*i)

