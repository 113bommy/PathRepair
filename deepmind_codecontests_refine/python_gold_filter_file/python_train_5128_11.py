import math
def ok(a,cantidad, cota):
	ans = []
	for i in range(len(a)):
		if a[i]<=cota:
			if not ans or ans[-1]<i-1:
				ans.append(i)

	return len(ans)>= cantidad


n, k = map(int, input().split())
a = [int(x) for x in input().split()]
impares = math.ceil(k/2)
pares = int(k/2)

l,r = min(a), 10**9+5
ans = r

while(l<=r):
	mid = (l+r)//2
	if k&1:
		if(ok(a,impares,mid) or ok(a[1:-1],pares,mid)):
			ans = mid
			r = mid-1
		else:
			l = mid+1
	else:
		if(ok(a[:-1],impares,mid) or ok(a[1:],pares,mid)):
			ans = mid
			r = mid-1
		else:
			l = mid+1

print(ans)