import sys
import array

from operator import itemgetter

def main():



	input = sys.stdin.readline


	md = 998244353
	n = int(input())
	tl=n+1
	
	ft=[0]*tl

	xy = [[0]*2 for _ in range(n)]
	for i in range(n):
		xy[i] = [int(item) for item in input().split()]
	xy.sort(key=itemgetter(0))
	yxi = [y for x, y in xy]

	*YS, = set(yxi)
	YS.sort()
	yxi= list(map({e: i for i, e in enumerate(YS)}.__getitem__, yxi))

	ct=[0]*(n+1)
	ct[0]=1
	for i in range(1,n+1):
		ct[i]=ct[i-1]*2%md

	cnt=tuple(ct)

	def upd(i):
		i+=1
		while(i<=n):
			ft[i]+=1
			i+=i&-i

	def get(i):
		i+=1
		ret=0
		while(i!=0):
		    ret+=ft[i]
		    i-=i&-i
		return ret

	def calc(get,upd):
		for i, y in enumerate(yxi):
			v = get(y); upd(y)
			p1 = cnt[v]; p0 = cnt[y - v]
			q1 = cnt[i - v]; q0 = cnt[(n - y - 1) - (i - v)]
			yield (p0 + p1 + q0 + q1 - (p0 + q1) * (p1 + q0)) % md


	print((sum(calc(get,upd))+n*cnt[n] - n)%md)

main()
