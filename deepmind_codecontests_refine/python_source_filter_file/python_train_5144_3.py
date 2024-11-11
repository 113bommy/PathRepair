def main(lst,l):
	lst.sort()
	c = 0
	for i in range(len(lst)):
		if lst[i] < 0:
			c+=lst[i]

	return abs(c)





if __name__ == '__main__':
	n,l = map(int, input().split())
	lst = list(map(int,input().split()))
	
	print(main(lst,l))






	

	


