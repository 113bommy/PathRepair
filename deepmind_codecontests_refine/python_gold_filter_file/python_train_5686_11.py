
def main():
	n = int(input())
	lst = list()
	for i in range(n):
	    line = input()
	    l,r = map(int,line.split())
	    lst.append((l,r))
	lst.sort()
	tv1 = [(-1,-1)]
	tv2 = [(-1,-1)]
	for i in range(n):
		if  lst[i][0] > tv1[-1][1] :
			tv1.append( lst[i])
		elif lst[i][0] > tv2[-1][1]:
			tv2.append( lst[i])

	tv1.remove(tv1[0])
	tv2.remove(tv2[0])
	tv = tv1+tv2
	tv.sort()
	if lst != tv:
		return "NO"
	else:
		return "YES"







if __name__ == '__main__':
	rs =main()
	print(rs)