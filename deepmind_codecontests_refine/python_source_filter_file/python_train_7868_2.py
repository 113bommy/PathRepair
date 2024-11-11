n = int(input())
arr = [int(x) for x in input().split()]
if n==1:
	print("NO")
	exit(0)
s = sum(arr)
sp = 0
ss = s
setq = {}
setp = {}
for i in arr:
	setq[i] = setq.get(i,0)+1
	setp[i] = 0
for i in range(n):
	sp += arr[i]
	ss -= arr[i]
	setp[arr[i]] += 1
	setq[arr[i]] -= 1
	val = ss-sp
	if val>0 and not val&1:
		val //= 2
		ans = setq.get(val,0)
		if ans:
			print("YES")
			exit(0)
	elif val<0 and not -val&i:
		val = -val
		val //= 2
		ans = setq.get(val,0)
		if ans:
			print("YES")
			exit(0)
	elif val==0:
		print("YES")
		exit(0)
print("NO")
