# f = open('test.py')
# def input():
# 	return f.readline().replace('\n','')

# import heapq
# from collections import defaultdict
def read_list():
	return list(map(int,input().strip().split(' ')))
def print_list(l):
	print(' '.join(map(str,l)))
INF = 10**18

N = int(input())
for _ in range(N):
	n,k = read_list()
	base = k*(k+1)//2
	dlt = n-base
	res = INF
	# print('dlt',dlt)
	if dlt>=0 and dlt%(k+1)==0:
		tmp = []
		now = dlt//(k+1)
		tt = min(now,9-k)
		tmp.append(tt)
		now-=tt 
		# print(now,tt)
		while now>=9:
			now-=9
			tmp.append(9)
		tmp.append(now)
		tmp = int(''.join(map(str,tmp[::-1])))
		res = min(tmp,res)
	for n9 in range(1,(n//9)+1):
		for t in range(k,0,-1):
			if (dlt+n9*t*9)%(k+1)==0:
				now = (dlt+n9*t*9)//(k+1)
				# print('now',now,n9,t)
				tmp = []
				tt = 9-k+t
				if now<(n9-1)*9+tt:
					continue

				tmp.append(tt)
				now-=tt
				for _ in range(max(0,n9-1)):
					tmp.append(9)
					now-=9
				if now>8:
					tmp.append(8)
					now-=8
					while now>=9:
						tmp.append(9)
						now-=9
				tmp.append(now)
				tmp = int(''.join(map(str,tmp[::-1])))
				res = min(tmp,res)

	if res==INF:
		print(-1)
	else:
		print(res)





			
	