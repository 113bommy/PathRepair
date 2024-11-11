
def eating_soup(total,m):
	
	if total==m:
		return 0
	elif m==0:
		return total
	elif m==total//2:
		return m
	else:
		whole=1
		i=1
		if m>total//2:
			m=total-m
		while i<m:
			if whole<=total//2:
				whole+=1
			i+=1
		return whole

			





Input=(input("")).split(" ")
print(eating_soup(int(Input[0]),int(Input[1])))