
if __name__=='__main__':
	n, k = map(int, input().split())
	ln = [0 for _ in range(101)]
	#pwrds = []
	for i in range(n):
		#pwrds.append(input())
		ln[len(input())] += 1
	pw = len(input())
	res = 0
	for i in range(1, pw):
		res += ln[i]
	print(res+1+ 5*(res // k), res+ln[pw]+ 5*((res+ln[pw]) // k))