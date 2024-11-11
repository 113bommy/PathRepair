def main(lst):
	res_lst = []

	for i in lst:
		res_lst.append((24*60) - (i[0] * 60 + i[1]))

	return res_lst
	



if __name__=='__main__':
	n = int(input())
	lst = []
	for i in range(n):
		lst.append(list(map(int,input().split())))
	print(*main(lst))